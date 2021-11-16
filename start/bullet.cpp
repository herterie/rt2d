/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "bullet.h"

Vector2 vec;
int spd = 500;

MyBullet::MyBullet() : Entity()
{
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
