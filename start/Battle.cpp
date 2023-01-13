/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "Battle.h"


Battle::Battle() : Scene()
{
	//new
	//player = new Player;
	enemy = new Enemy;

	//position
	player->position.y = 370;
	player->position.x = 315;

	enemy->position.y = 390;
	enemy->position.x = 963;

	//add child
	addChild(player);
}

Battle::~Battle()
{
	this->removeChild(player);
	this->removeChild(enemy);

	delete player;
	delete enemy;
}

void Battle::update(float deltaTime)
{

}

