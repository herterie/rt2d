/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "ActionButton.h"
#include "UiButton.h"
#include "ItemFrame.h"
#include "Inventory.h"
#include "Player.h"
#include "Enemy.h"
#include "Battle.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	//creating mouse x and y cords
	int mousex;
	int mousey;

	bool ShowInventoryIcon;
	bool ShowInventory;

	Player* player;
	Enemy* enemy;

	UiButton* InventoryButton;
	UiButton* SettingButton;

	ActionButton* StartBattle;

	Inventory* inventory;
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//variabels

	//Vectors for buttons
	//std::vector<ActionButton*> BtnList;

	/// @brief Buttons
	//ActionButton* Button1;
	//ActionButton* Button2;


};

#endif /* SCENE00_H */
