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
}

SpaceBee::~SpaceBee()
{
	
}

void SpaceBee::update(float deltaTime)
{
	beeVelocity.x = 0;
	beeVelocity.normalize();

	this->position.x += (beeVelocity.x * beeSpeed) * deltaTime;
}
