/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "Enemy.h"


Enemy::Enemy() : Scene()
{
	this->addSprite("assets/CharacterSprites/EnemySpriteConcept.tga");

	MaxHp = 100.0f;
	Hp = MaxHp;
	Armor = 0;

	armorIcon = new Icon;
	armorIcon->addSprite("assets/HUD/DefendIntent.tga");
	armorIcon->position.y = 107;
	armorIcon->position.x = 95;
	
	Text* armorText = new Text();
	armorText->position.y = 107;
	if (Armor < 10) {
		armorText->position.x = 95;
	}
	else if (Armor < 100) {
		armorText->position.x = 80;
	}
	else {
		armorText->position.x = 65;
	}
	armorText->scale = Point2(1.0f, 1.0f);
	armorText->message(std::to_string(Armor));
	

	//Hp text
	Text* HpText = new Text();
	HpText->position.y = 97;
	HpText->position.x = -19;
	HpText->scale = Point2(0.3f, 0.3f);
	HpText->message(std::to_string(int(Hp)) + "/" + std::to_string(int(MaxHp)));

	//Hp bar
	HpBackBar = new ProgressBar(0);
	HpBar = new ProgressBar(1);

	HpBackBar->position.y = 89;
	HpBackBar->position.x = -63;
	HpBar->position.y = 89;
	HpBar->position.x = -63;

	//addChild
	addChild(armorIcon);
	addChild(armorText);
	addChild(HpBackBar);
	addChild(HpBar);
	addChild(HpText);
}

Enemy::~Enemy()
{
	this->removeChild(armorIcon);
	this->removeChild(HpBackBar);
	this->removeChild(HpBar);

	delete armorIcon;
	delete HpBackBar;
	delete HpBar;
}

void Enemy::update(float deltaTime)
{
	float pc = (Hp / MaxHp) * 1.0f;
	HpBar->scale = Point3(pc, 1.0f, 1.0f);
}

