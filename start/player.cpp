/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "player.h"



MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/PlayerConcept.tga");
	this->addSprite("assets/square.tga");
	// text[0]->message("Test");
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{
	//nothing
}
