/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "Player.h"


Player::Player() : Scene()
{
	this->addSprite("assets/CharacterSprites/PlayerSpriteConcept.tga");

	MaxHp = 100.0f;
	Hp = 50.0f;
	MaxMana = 20.0f;
	Mana = 15.0f;
	Armor = 0.0f;

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
	
	addChild(HpBackBar);
	addChild(HpBar);
	addChild(ManaBackBar);
	addChild(ManaBar);
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	float pc = (Hp / MaxHp) * 1.0f;
	float mc = (Mana / MaxMana) * 1.0f;
	HpBar->scale = Point3(pc, 1.0f, 1.0f);
	ManaBar->scale = Point3(mc, 1.0f, 1.0f);
}

