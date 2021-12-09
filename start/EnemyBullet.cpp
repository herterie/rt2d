/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "EnemyBullet.h"

Vector2 stingerVelocity;
int stingerSpeed = 500;

EnemyBullet::EnemyBullet() : Entity()
{
	this->addSprite("assets/Stinger.tga");
}

EnemyBullet::~EnemyBullet()
{

}

void EnemyBullet::update(float deltaTime)
{
	stingerVelocity.y = +1;

	this->position.y += (stingerVelocity.y * stingerSpeed) * deltaTime;
}
