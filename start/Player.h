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
#include <rt2d/text.h>
#include "ProgressBar.h"
#include "Icon.h"
#include "Inventory.h"
#include "ItemFrame.h"

 /// @brief The MyScene class is the Scene implementation.
class Player : public Scene
{
public:
	float MaxHp;
	float Hp;
	float MaxMana;
	float Mana;
	int Armor;
	int Energy;
	int Strenght;
	int Dexterity;
	int Intellect;
	int luck;

	std::vector<ItemFrame*> Equipment;

	Inventory* inventory;

	ProgressBar* HpBackBar;
	ProgressBar* HpBar;

	ProgressBar* ManaBackBar;
	ProgressBar* ManaBar;

	Icon* armorIcon;
	Icon* energyIcon;

	Text* energyText;
	Text* armorText;
	Text* HpText;
	Text* ManaText;
	/// @brief Constructor
	Player(Inventory* inv);
	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void ChangeStats();

private:
	//variabels
};

#endif /* PLAYER_H */
