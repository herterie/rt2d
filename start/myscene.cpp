/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

MyScene::MyScene() : Scene()
{
	// Background sprite
	this->addSprite("assets/Space1.tga");
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new Player();
	myentity->position = Point2(SWIDTH/2, SHEIGHT/2);

	spacebee = new SpaceBee();
	spacebee->position = Point2(SWIDTH / 2, 40);

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
		stinger = new Stinger();
		stinger->position = spacebee->position;
		stinger->position.y += 30;
		this->addChild(stinger);
		t.start();
	}

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
