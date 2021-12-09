/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

//bool CheckCollision(Player& pl, SpaceBee& sb);

int Enemies[1][4];  //declaration of enemies 2D array  
int player[4];  //declaration of player array  

bool CheckCollision(Player& pl, SpaceBee& sb);

MyScene::MyScene() : Scene()
{
	//initialization player array
	player[0] = -64; // x1
	player[1] = -64; // y1
	player[2] = 64; // x2
	player[3] = 64; // y2

	//initialization enemy 2d array
	Enemies[0][0] = -32; // x1
	Enemies[0][1] = -32; // y1
	Enemies[0][2] = 32; // x2
	Enemies[0][3] = 32; // y2


	// Background sprite
	this->addSprite("assets/Space1.tga");
	// start the timer.
	t.start();


	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new Player();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);
	myentity->ddSquare(-64, -64, 128, 128, RED);

	spacebee = new SpaceBee();
	spacebee->position = Point2(SWIDTH / 2, 70);
	spacebee->ddSquare(-32, -32, 64, 64, RED);

	// create the scene 'tree'
	// add myentity to this Scene as a child.
	this->addChild(myentity);
	this->addChild(spacebee);
}


MyScene::~MyScene()
{	
	this->removeChild(myentity);
	this->removeChild(spacebee);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete spacebee;

	if (bullet != nullptr) {
		bullet = nullptr;
	}
	else {
		this->removeChild(bullet);
		delete bullet;
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
	if (input()->getKeyDown(KeyCode::Space)) {
		bullet = new MyBullet();
		bullet->position = myentity->position;
		bullet->position.y -= 80;
		this->addChild(bullet);
	}
	if (t.seconds() > 2.0f) {
		stinger = new EnemyBullet();
		stinger->position = spacebee->position;
		stinger->position.y += 30;
		//this->addChild(stinger);
		t.start();
	}

	if (CheckCollision(*myentity, *spacebee)) {
		spacebee->ddSquare(-32, -32, 64, 64, GREEN);
	}
	else {
		spacebee->ddSquare(-32, -32, 64, 64, RED);
	}

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

bool CheckCollision(Player& pl, SpaceBee& sb) { // AABB - AABB collision
	return (pl.position.x + player[0] < sb.position.x + Enemies[0][2] && // player x lesser then enemy x
		pl.position.x + player[2] > sb.position.x + Enemies[0][0] && // player x more then enemy x
		pl.position.y + player[1] < sb.position.y + Enemies[0][3] && // player y lesser then enemy y
		pl.position.y + player[3] > sb.position.y + Enemies[0][1]); // player y more then enemy y
}

