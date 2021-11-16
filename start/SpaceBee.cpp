/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "SpaceBee.h"

Vector2 beeVelocity;
int beeSpeed = 300;


SpaceBee::SpaceBee() : Entity()
{
	this->addSprite("assets/SpaceBee.tga");
	//stinger = new Stinger();
	//stinger->position = this->position;
}

SpaceBee::~SpaceBee()
{
	//this->removeChild(stinger);

	//delete stinger;
}

void SpaceBee::update(float deltaTime)
{
	//this->addChild(stinger);

	beeVelocity.x = 0;
	beeVelocity.normalize();

	this->position.x += (beeVelocity.x * beeSpeed) * deltaTime;
}
