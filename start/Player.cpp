/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "Player.h"


Player::Player(Inventory* inv) : Scene()
{
	this->addSprite("assets/CharacterSprites/PlayerSpriteConcept.tga");

	inventory = inv;

	Energy = 3;
	MaxHp = 100.0f;
	Hp = MaxHp;
	MaxMana = 20.0f;
	Mana = MaxMana;
	Armor = 0;
	Strenght = 0;
	Dexterity = 0;
	Intellect = 0;
	luck = 0;

	//energy icon and text
	energyIcon = new Icon;
	energyIcon->addSprite("assets/HUD/EnergyIcon.tga");
	energyIcon->position.y = 28;
	energyIcon->position.x = -216;

	energyText = new Text();
	energyText->position.y = 30;
	energyText->position.x = -214;
	energyText->scale = Point2(1.3f, 1.3f);
	energyText->message(std::to_string(Energy));

	//armor icon and text
	armorIcon = new Icon;
	armorIcon->addSprite("assets/HUD/DefendIntent.tga");
	armorIcon->position.y = 125;
	armorIcon->position.x = -95;

	armorText = new Text();
	armorText->position.y = 125;
	
	armorText->scale = Point2(1.0f, 1.0f);
	armorText->message(std::to_string(Armor));

	//Hp and mana text
	HpText = new Text();
	HpText->position.y = 115;
	HpText->position.x = -19;
	HpText->scale = Point2(0.3f, 0.3f);
	HpText->message(std::to_string(int(Hp)) + "/" + std::to_string(int(MaxHp)));

	ManaText = new Text();
	ManaText->position.y = 139;
	ManaText->position.x = -19;
	ManaText->scale = Point2(0.3f, 0.3f);
	ManaText->message(std::to_string(int(Mana)) + "/" + std::to_string(int(MaxMana)));
	
	//Hp and mana bar
	HpBackBar = new ProgressBar(0);
	HpBar = new ProgressBar(1);

	ManaBackBar = new ProgressBar(0);
	ManaBar = new ProgressBar(2);
	
	HpBackBar->position.y = 107;
	HpBackBar->position.x = -63;
	HpBar->position.y = 107;
	HpBar->position.x = -63;

	ManaBackBar->position.y = 131;
	ManaBackBar->position.x = -63;
	ManaBar->position.y = 131;
	ManaBar->position.x = -63;
	
	//addChild
	addChild(energyIcon);
	addChild(energyText);
	addChild(armorIcon);
	addChild(armorText);
	addChild(HpBackBar);
	addChild(HpBar);
	addChild(ManaBackBar);
	addChild(ManaBar);
	addChild(HpText);
	addChild(ManaText);

	Equipment.push_back(inventory->WeaponFrame);
	Equipment.push_back(inventory->OffHandFrame);
	Equipment.push_back(inventory->HelmFrame);
	Equipment.push_back(inventory->ChestFrame);
	Equipment.push_back(inventory->PantsFrame);
	Equipment.push_back(inventory->BootsFrame);
	Equipment.push_back(inventory->NecklessFrame);
	Equipment.push_back(inventory->RingFrame);
	ChangeStats();
}

Player::~Player()
{
	this->removeChild(energyIcon);
	this->removeChild(armorIcon);
	this->removeChild(HpBackBar);
	this->removeChild(HpBar);
	this->removeChild(ManaBackBar);
	this->removeChild(ManaBar);

	delete energyIcon;
	delete armorIcon;
	delete HpBackBar;
	delete HpBar;
	delete ManaBackBar;
	delete ManaBar;
}

void Player::update(float deltaTime)
{
	float pc = (Hp / MaxHp) * 1.0f;
	float mc = (Mana / MaxMana) * 1.0f;
	HpBar->scale = Point3(pc, 1.0f, 1.0f);
	ManaBar->scale = Point3(mc, 1.0f, 1.0f);
	armorText->message(std::to_string(Armor));

	if (Armor < 10) {
		armorText->position.x = -95;
	}
	else if (Armor < 100) {
		armorText->position.x = -110;
	}
	else {
		armorText->position.x = -125;
	}
	ChangeStats();
}

void Player::ChangeStats() {
	Armor = 0;
	Strenght = 0;
	Dexterity = 0;
	Intellect = 0;
	luck = 0;
	for (int i = 0; i < Equipment.size(); i++) {
		switch (Equipment[i]->SpriteIndex)
		{
		case 1:
			Strenght += 5;
				break;
		case 2:
			Dexterity += 7;
			break;
		case 3:
			Intellect += 5;
			break;
		case 4:
			Armor += 3;
			break;
		case 5:
			Dexterity += 3;
			break;
		case 6:
			Intellect += 3;
			break;
		case 7:
			Armor += 3;
			Strenght += 1;
			break;
		case 8:
			Armor += 2;
			Dexterity += 1;
			break;
		case 9:
			Armor += 1;
			Intellect += 3;
			break;
		case 10:
			Armor += 3;
			Strenght += 1;
			break;
		case 11:
			Armor += 2;
			Dexterity += 1;
			break;
		case 12:
			Armor += 1;
			Intellect += 3;
			break;
		case 13:
			Armor += 3;
			Strenght += 1;
			break;
		case 14:
			Armor += 2;
			Dexterity += 1;
			break;
		case 15:
			Armor += 1;
			Intellect += 3;
			break;
		case 16:
			Armor += 3;
			Strenght += 1;
			break;
		case 17:
			Armor += 2;
			Dexterity += 1;
			break;
		case 18:
			Armor += 1;
			Intellect += 3;
			break;
		case 19:
			Strenght += 3;
			break;
		case 20:
			Dexterity += 3;
			break;
		case 21:
			Intellect += 3;
			break;
		case 22:
			Strenght += 3;
			break;
		case 23:
			Dexterity += 3;
			break;
		case 24:
			Intellect += 3;
			break;
		default:
			break;
		}
	}
}

