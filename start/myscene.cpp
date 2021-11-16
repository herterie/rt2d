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
	// start the timer.
	t.start();

	// create a single instance of MyEntity in the middle of the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
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
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(bullet);
	this->removeChild(spacebee);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete bullet;
	delete spacebee;
}

void MyScene::update(float deltaTime)
{
	if (input()->getKeyDown(KeyCode::Space)) {
		bullet = new MyBullet();
		bullet->position = myentity->position;
		bullet->position.y -= 80;
		this->addChild(bullet);
	}
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}
