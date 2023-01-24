/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef BATTLE_H
#define BATTLE_H

#include <rt2d/scene.h>
#include "Enemy.h"
#include "Player.h"
#include <rt2d/text.h>

 /// @brief The MyScene class is the Scene implementation.
class Battle : public Scene
{
public:
	Player* player;
	//Enemy* enemy;

	/// @brief Constructor
	Battle(Player* pl);
	/// @brief Destructor
	virtual ~Battle();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//variabels
};

#endif /* BATTLE_H */#pragma once
