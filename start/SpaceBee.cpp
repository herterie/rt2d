/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "SpaceBee.h"



SpaceBee::SpaceBee(int type) : Entity()
{
	beeType = type;

	switch (beeType)
	{
	default:
		this->addSprite("assets/SpaceBee.tga");
		break;
	case 1:
		this->addSprite("assets/SpaceBee.tga");
		break;
	case 2:
		this->addSprite("assets/BeeKeeper.tga");
		break;
	}
}

SpaceBee::~SpaceBee()
{
	
}

void SpaceBee::update(float deltaTime)
{
	beeVelocity.x = 0;
	beeVelocity.normalize();

	this->position.x += (beeVelocity.x * beeSpeed) * deltaTime;

	if ((Health <= 0) && (alive == true)){
		this->ddSquare(-32, -32, 64, 64, GREEN);
		alive = false;
	}
}

void SpaceBee::TakeDamage(int dmg) {
	Health -= dmg;
}
	

bool SpaceBee::IsDeath() {
	if (Health <= 0) {
		return true;
	}
	else {
		return false;
	}
}