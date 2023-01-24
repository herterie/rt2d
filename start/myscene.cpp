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
	BattleStarted = false;

	//new
	inventory = new Inventory();

	player = new Player(inventory);

	enemy = new Enemy();

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
		BattleStarted = true;
		inventory->RemoveMenu();
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
		inventory->RemoveMenu();
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
	if (BattleStarted) {
		Battle();
	}
}

void MyScene::Battle() {
	int BattleState = 0;
	Abilitie* ab1;
	Abilitie* ab2;
	Abilitie* ab3;
	Abilitie* ab4;
	switch (BattleState)
	{
	case 0://choose target and attack
		switch (player->inventory->WeaponFrame->SpriteIndex)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			ab1 = new Abilitie(6);
			ab2 = new Abilitie(7);

			ab1->position.x = 150;
			ab1->position.y = 300;

			ab2->position.x = 250;
			ab2->position.y = 300;

			this->addChild(ab1);
			this->addChild(ab2);
			break;
		default:
			break;
		}
		break;
	case 1://do attack and check for energy

		break;
	case 2://Enemy attacks

		break;
	default:
		break;
	}
}

