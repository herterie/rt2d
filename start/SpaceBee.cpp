/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "SpaceBee.h"

int SpaceBee::nextGuid = 0;

SpaceBee::SpaceBee(int type) : Entity()
{
	guid = nextGuid;
	nextGuid++;

	beeType = type;

	switch (beeType)
	{
	default:
		this->addSprite("assets/SpaceBee.tga");
		BeeYPosition = 70;
		break;
	case 1:
		this->addSprite("assets/SpaceBee.tga");
		BeeYPosition = 70;
		break;
	case 2:
		this->addSprite("assets/BeeKeeper.tga");
		BeeYPosition = 140;
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

	if (this->position.y < BeeYPosition) {
		this->position.y += 1.5f;
	}

	if ((Health <= 0) && (alive == true)){
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

void SpaceBee::XMoveTo(int x) {
	if (this->position.x > x+1) {
		this->position.x -= 2;
	}else if (this->position.x < x-1){
		this->position.x += 2;
	}
}