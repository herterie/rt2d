/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"

Vector2 vec;
int spd = 500;
int MyBullet::_nextGuid = 0;

MyBullet::MyBullet() : Entity()
{
	_guid = _nextGuid;
	_nextGuid++;
	this->addSprite("assets/Bullet1.tga");
}

MyBullet::~MyBullet()
{

}

void MyBullet::update(float deltaTime)
{
	vec.y = -1;

	this->position.y += (vec.y * spd) * deltaTime;
}
