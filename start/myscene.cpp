/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "myscene.h"


MyScene::MyScene() : Scene()
{
	mousex = 0;
	mousey = 0;
	inventory = new Inventory();
	addChild(inventory);
}

MyScene::~MyScene()
{
	this->removeChild(inventory);

	delete inventory;
}

void MyScene::update(float deltaTime)
{	
	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

