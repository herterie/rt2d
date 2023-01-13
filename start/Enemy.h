/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <rt2d/scene.h>
#include "ProgressBar.h"
#include "Icon.h"
#include <rt2d/text.h>

 /// @brief The MyScene class is the Scene implementation.
class Enemy : public Scene
{
public:
	float MaxHp;
	float Hp;
	int Armor;

	ProgressBar* HpBackBar;
	ProgressBar* HpBar;

	Icon* armorIcon;
	//Icon* intentIcon;

	/// @brief Constructor
	Enemy();
	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//variabels
};

#endif /* ENEMY_H */#pragma once
