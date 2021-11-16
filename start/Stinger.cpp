/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Stinger.h"

Vector2 stingerVelocity;
int stingerSpeed = 500;

Stinger::Stinger() : Entity()
{
	this->addSprite("assets/Stinger.tga");
}

Stinger::~Stinger()
{

}

void Stinger::update(float deltaTime)
{
	stingerVelocity.y = +1;

	this->position.y += (stingerVelocity.y * stingerSpeed) * deltaTime;
}
