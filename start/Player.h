/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/scene.h>
#include "ProgressBar.h"

 /// @brief The MyScene class is the Scene implementation.
class Player : public Scene
{
public:
	float MaxHp;
	float Hp;
	float MaxMana;
	float Mana;
	float Armor;

	ProgressBar* HpBackBar;
	ProgressBar* HpBar;

	ProgressBar* ManaBackBar;
	ProgressBar* ManaBar;
	/// @brief Constructor
	Player();
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//variabels
};

#endif /* PLAYER_H */
