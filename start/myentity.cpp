/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "myentity.h"

Vector2 velocity;
int speed = 300;


MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/evan.tga");
}

MyEntity::~MyEntity()
{

}

void MyEntity::update(float deltaTime)
{

	velocity.x = (input()->getKey(KeyCode::D) - input()->getKey(KeyCode::A));
	velocity.y = (input()->getKey(KeyCode::S) - input()->getKey(KeyCode::W));
	velocity.normalize();

	this->position.x += (velocity.x * speed) * deltaTime;
	this->position.y += (velocity.y * speed) * deltaTime;
}
