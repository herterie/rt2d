/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "myscene.h"


MyScene::MyScene() : Scene()
{
	this->addSprite("assets/Backgrounds/TestFightBackground.tga");
	sprite()->pivot = Point2(0.0f, 0.3f);
	mousex = 0;
	mousey = 0;

	ShowInventoryIcon = true;
	ShowInventory = false;

	//new
	inventory = new Inventory();

	player = new Player(inventory);
	enemy = new Enemy;

	InventoryButton = new UiButton(0);
	SettingButton = new UiButton(1);

	StartBattle = new ActionButton("Battle");

	//position
	player->position.y = 370;
	player->position.x = 315;

	enemy->position.y = 390;
	enemy->position.x = 963;

	SettingButton->position.y = 42;

	StartBattle->position.y = SHEIGHT / 2;
	StartBattle->position.x = SWIDTH / 2;

	//add child
	addChild(player);
	addChild(enemy);
	addChild(InventoryButton);
	addChild(SettingButton);
	addChild(inventory);
	addChild(StartBattle);
}

MyScene::~MyScene()
{
	this->removeChild(player);
	this->removeChild(enemy);
	this->removeChild(InventoryButton);
	this->removeChild(SettingButton);
	this->removeChild(inventory);

	delete player;
	delete enemy;
	delete InventoryButton;
	delete SettingButton;
	delete inventory;
	delete StartBattle;
}

void MyScene::update(float deltaTime)
{	
	if (StartBattle->pressed) {
		ShowInventoryIcon = false;
		ShowInventory = false;
		this->removeChild(StartBattle);
	}
	if (InventoryButton->Leftpressed) {
		if (ShowInventory) {
			ShowInventory = false;
		}
		else {
			ShowInventory = true;
		}
	}
	if (ShowInventory) {
		inventory->position.y = 0;
		inventory->position.x = 0;
	}
	else {
		inventory->position.y = -1500;
		inventory->position.x = -1500;
	}
	if (ShowInventoryIcon) {
		InventoryButton->position.y = 42;
		InventoryButton->position.x = SWIDTH / 2 - 37;
		SettingButton->position.x = SWIDTH / 2 + 37;
	}
	else {
		InventoryButton->position.y = -1500;
		InventoryButton->position.x = -1500;
		SettingButton->position.x = SWIDTH / 2;
	}
	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

