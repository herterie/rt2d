/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "myscene.h"

MyScene::MyScene() : Scene()
{
	//initialization player array
	player[0] = -64; // x1
	player[1] = -64; // y1
	player[2] = 64; // x2
	player[3] = 64; // y2
	player[4] = 50; // damage

	//initialization enemy 2d array
	// 0 = enemy 1 and 2,
	Enemies[0][0] = -32; // x1
	Enemies[0][1] = -32; // y1
	Enemies[0][2] = 32; // x2
	Enemies[0][3] = 32; // y2
	Enemies[0][4] = -2; // x1 for bullet
	Enemies[0][5] = -4; // y1 for bullet
	Enemies[0][6] = 2; // x2 for bullet
	Enemies[0][7] = 4; // y2 for bullet

	// Background sprite
	this->addSprite("assets/Space1.tga");

	// start the timers.
	EnemyAttackSpeed.start();
	AttaskSpeed.start();
	BulletReloadTimer.start();


	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new Player();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	myentity->ddSquare(-64, -64, 128, 128, RED);

	SpawnEnemy(1);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
}


MyScene::~MyScene()
{	
	this->removeChild(myentity);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;

	for (int i = 0; i < EnemyList.size(); i++) {
		if (EnemyList[i] != nullptr) {
			EnemyList[i] = nullptr;
			delete EnemyList[i];
		}
		else {
			this->removeChild(BulletList[i]);
			delete EnemyList[i];
		}
	}
	// remove and delete bullets
	for (int i = 0; i < BulletList.size(); i++) {
		if (BulletList[i] != nullptr) {
			BulletList[i] = nullptr;
			delete BulletList[i];
		}
		else {
			this->removeChild(BulletList[i]);
			delete BulletList[i];
		}
	}
	// remove and delete bullets
	for (int i = 0; i < EnemyBulletList.size(); i++) {
		if (EnemyBulletList[i] != nullptr) {
			EnemyBulletList[i] = nullptr;
			delete EnemyBulletList[i];
		}
		else {
			this->removeChild(EnemyBulletList[i]);
			delete EnemyBulletList[i];
		}
	}
	if (stinger != nullptr) {
		stinger = nullptr;
	}
	else {
		this->removeChild(stinger);
		delete stinger;
	}
}

void MyScene::update(float deltaTime)
{
	//border
	if (myentity->position.x >= SWIDTH - player[2]) {
		myentity->position.x = SWIDTH - player[2];
	}
	if (myentity->position.x <= 0 - player[0]) {
		myentity->position.x = 0 - player[0];
	}
	if (myentity->position.y >= SHEIGHT - player[3]) {
		myentity->position.y = SHEIGHT - player[3];
	}
	if (myentity->position.y <= 0 - player[1]) {
		myentity->position.y = 0 - player[1];
	}

	// enemy spawn

	// enemy movement

	//player shoot
	if (input()->getKey(KeyCode::Space)) {
		if (AttaskSpeed.seconds() > 0.2f) {
			MyBullet* bullet = new MyBullet();
			BulletList.push_back(bullet);
			bullet->position = myentity->position;
			bullet->position.y -= 80;
			this->addChild(bullet);
			bullet->ddSquare(-8, -15, 16, 34, RED);
			AttaskSpeed.start();
		}
	}

	// enemy shoot
	if (EnemyAttackSpeed.seconds() > 2.0f) {
		for (int i = 0; i < EnemyList.size(); i++) {
			if (!EnemyList[i]->IsDeath()) {
				if (EnemyList[i]->beeType == 1) {
					stinger = new EnemyBullet();
					EnemyBulletList.push_back(stinger);
					stinger->position = EnemyList[i]->position;
					stinger->position.y += 30;
					this->addChild(stinger);
					EnemyAttackSpeed.start();
				}
			}
		}	
	}

	//check player and enemy collision
	for (int i = 0; i < EnemyList.size(); i++) {
		if (CheckPlayerToEnemyCollision(*myentity, *EnemyList[i])) {
			EnemyList[i]->TakeDamage(player[4]);
			//EnemyList[i]->ddSquare(-32, -32, 64, 64, GREEN);
			myentity->TakeDamage(50);
		}
	}

	//check enemy death
	for (int i = 0; i < EnemyList.size(); i++) {
		if (EnemyList[i]->IsDeath()) {
			removeChild(EnemyList[i]);
			EnemyList.erase(EnemyList.begin()+i);
		}
	}
	
	//check bullet collsion
	
	// player bullet to enemy check
	for (int i = 0; i < BulletList.size(); i++) {
		for (int ii = 0; ii < EnemyList.size(); ii++)
		if (CheckPbulletToEnemyCollision(*BulletList[i], *EnemyList[ii])) {
			EnemyList[ii]->TakeDamage(player[4]);
			this->removeChild(BulletList[i]);
			BulletList.erase(BulletList.begin() + i);
		}
	}

	// enemy bullet to player check
	for (int i = 0; i < EnemyBulletList.size(); i++) {
		if (CheckEbulletToEPlayerCollision(*myentity, *EnemyBulletList[i])) {
			//player takes dmg
			EnemyBulletList.erase(EnemyBulletList.begin() + i);
		}
	}
	
	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

// spawn enemys
void MyScene::SpawnEnemy(int type) {
	SpaceBee* spacebee = new SpaceBee(type);
	EnemyList.push_back(spacebee);
	spacebee->position = Point2(SWIDTH / 2 , 70);
	spacebee->ddSquare(-32, -32, 64, 64, RED);
	this->addChild(spacebee);
}

// player and enemy collision
 bool MyScene::CheckPlayerToEnemyCollision(Player& pl, SpaceBee& sb) { // AABB - AABB collisiontion.x
	return (pl.position.x + player[0] < sb.position.x + Enemies[0][2] && // player x lesser then enemy x
		pl.position.x + player[2] > sb.position.x + Enemies[0][0] && // player x more then enemy x
		pl.position.y + player[1] < sb.position.y + Enemies[0][3] && // player y lesser then enemy y
		pl.position.y + player[3] > sb.position.y + Enemies[0][1]); // player y more then enemy y
}

// player bullet and enemy collision
bool MyScene::CheckPbulletToEnemyCollision(MyBullet& pb, SpaceBee& sb) { // AABB - AABB collision
	return (pb.position.x - 8 < sb.position.x + Enemies[0][2] &&
		pb.position.x + 8 > sb.position.x + Enemies[0][0] && 
		pb.position.y - 15 < sb.position.y + Enemies[0][3] &&
		pb.position.y + 15 > sb.position.y + Enemies[0][1]);
}

// enemy bullet and player collision
bool MyScene::CheckEbulletToEPlayerCollision(Player& pl, EnemyBullet& eb) { // AABB - AABB collision
	return (pl.position.x + player[0] < eb.position.x + Enemies[0][6] &&
		pl.position.x + player[2] > eb.position.x + Enemies[0][7] &&
		pl.position.y + player[1] < eb.position.y + Enemies[0][3] &&
		pl.position.y + player[3] > eb.position.y + Enemies[0][5]);
}