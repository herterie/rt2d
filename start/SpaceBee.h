/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef SPACEBEE_H
#define SPACEBEE_H

#include <rt2d/entity.h>

#include "Stinger.h"

 /// @brief The MyEntity class is the Entity implementation.
class SpaceBee : public Entity
{
public:
	/// @brief Constructor
	SpaceBee();
	/// @brief Destructor
	virtual ~SpaceBee();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
	Stinger* stinger;
	Timer t;
};

#endif /* MYENTITY_H */
#pragma once