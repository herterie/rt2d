/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file SpaceBee.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SPACEBEE_H
#define SPACEBEE_H

#include <rt2d/entity.h>

 /// @brief The MyEntity class is the Entity implementation.
class SpaceBee : public Entity
{
public:
	/// @brief Constructor
	SpaceBee(int type);
	/// @brief Destructor
	virtual ~SpaceBee();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void SpaceBee::TakeDamage(int dmg);
	bool SpaceBee::IsDeath();

	int beeType = 0; // 1 = Worker Bee, 2 = Bee keeper,
private:
	/* add your private declarations */
	Vector2 beeVelocity;
	int beeSpeed = 300;
	int Health = 100;
	bool alive = true;
};

#endif /* SPACEBEE_H */
#pragma once
