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

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);

	WaveShow = new Ui();
	this->addChild(WaveShow);
	
}


MyScene::~MyScene()
{	
	this->removeChild(myentity);
	this->removeChild(WaveShow);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete WaveShow;

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
	if (EnemyList.size() <= 0) {
		WaveShow->ShowWaveRound(CurrentRound+1);
		switch (CurrentRound) {
		default:
			//end mission
			break;
		case 0:
			
			BackLine.clear();
			FrontLine.clear();
			SpawnEnemy(1);
			SpawnEnemy(2);
			PlaceEnemy();
			CurrentRound++;
			break;
		case 1:
			BackLine.clear();
			FrontLine.clear();
			SpawnEnemy(1);
			SpawnEnemy(1);
			SpawnEnemy(1);
			PlaceEnemy();
			CurrentRound++;
			break;
		case 2:
			BackLine.clear();
			FrontLine.clear();
			SpawnEnemy(1);
			SpawnEnemy(1);
			SpawnEnemy(1);
			SpawnEnemy(2);
			SpawnEnemy(2);
			SpawnEnemy(2);
			PlaceEnemy();
			CurrentRound++;
			break;
		case 3:
			SpawnEnemy(1);
			//end mission
			break;
		}
	}
	
	/*
	// enemy movement
	if (EnemyList.size() > 0) {
		for (int i = 0; i < EnemyList.size(); i++) {
			if (EnemyList[i]->beeType != 2) {
				EnemyList[i]->XMoveTo(SWIDTH / (EnemyList.size() + 1) + ((SWIDTH / (EnemyList.size() + 1)) * i));
			}
		}
	}

	
	if (EnemyList.size() > 0) {
		for (int i = 0; i < EnemyList.size(); i++) {
			if (EnemyList[i]->beeType != 2) {
				BackLine.push_back(EnemyList[i]);
			}
		}
		for (int i = 0; i < BackLine.size(); i++) {
			BackLine[i]->XMoveTo(SWIDTH / (BackLine.size() + 1) + ((SWIDTH / (BackLine.size() + 1)) * i));
		}
	}
	*/
	if (input()->getKeyDown(KeyCode::J)) {
		SpawnEnemy(1);
		SpawnEnemy(1);
		SpawnEnemy(1);
		SpawnEnemy(1);
		SpawnEnemy(2);
		SpawnEnemy(2);
		SpawnEnemy(2);
		SpawnEnemy(2);
		PlaceEnemy();
	}

	//player shoot
	if (input()->getKey(KeyCode::Space)) {
		if (AttaskSpeed.seconds() > 0.2f) {
			MyBullet* bullet = new MyBullet();
			BulletList.push_back(bullet);
			bullet->position = myentity->position;
			bullet->position.y -= 80;
			this->addChild(bullet);
			AttaskSpeed.start();
		}
	}

	// enemy shoot
	if ((EnemyAttackSpeed.seconds() > 2.0f) && EnemyList.size() > 0){
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
			myentity->TakeDamage(player[4]);
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
		for (int j = 0; j < EnemyList.size(); j++) {
			if (CheckPbulletToEnemyCollision(*BulletList[i], *EnemyList[j])) {
				EnemyList[j]->TakeDamage(player[4]);
				this->removeChild(BulletList[i]);
				removeBullet(BulletList[i]);
				break;
			}
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

void MyScene::removeBullet(MyBullet* bullet) {
	std::vector< MyBullet* >::iterator it = BulletList.begin();
	while (it != BulletList.end()) {
		if ((*it)->_guid == bullet->_guid) {
			it = BulletList.erase(it);
		}
		else {
			++it;
		}
	}
}


// spawn enemys
void MyScene::SpawnEnemy(int type) {
	SpaceBee* spacebee = new SpaceBee(type);
	EnemyList.push_back(spacebee);
	if (spacebee->beeType != 2) {
		BackLine.push_back(spacebee);
		spacebee->position = Point2(SWIDTH / 2, -140);
	}
	else {
		FrontLine.push_back(spacebee);
		spacebee->position = Point2(SWIDTH / 2, -70);
	}
	this->addChild(spacebee);
}

void MyScene::PlaceEnemy() {
	if (EnemyList.size() > 0) {
		for (int i = 0; i < BackLine.size(); i++) {
			BackLine[i]->position.x = (SWIDTH / (BackLine.size() + 1) + ((SWIDTH / (BackLine.size() + 1)) * i));
		}
		for (int i = 0; i < FrontLine.size(); i++) {
			FrontLine[i]->position.x = (SWIDTH / (FrontLine.size() + 1) + ((SWIDTH / (FrontLine.size() + 1)) * i));
		}
	}
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