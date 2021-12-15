/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "SpaceBee.h"

Vector2 beeVelocity;
int beeSpeed = 300;
int Enemyhealth = 100;
int beeType = 0; // 1 = Worker Bee, 2 = Bee keeper,
bool death = false;

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

	if ((Enemyhealth <= 0) && (death == false)){
		this->ddSquare(-32, -32, 64, 64, GREEN);
		death = true;
	}
}

void SpaceBee::TakeDamage(int dmg) {
	Enemyhealth -= dmg;
}

bool SpaceBee::Alive() {
	if (Enemyhealth <= 0) {
		return true;
	}
	else {
		return false;
	}
}