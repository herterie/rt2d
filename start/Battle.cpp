/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "Battle.h"


Battle::Battle(Player* pl) : Scene()
{
	//new
	player = pl;

	//position
	player->position.y = 370;
	player->position.x = 315;

	//add child
	addChild(player);
}

Battle::~Battle()
{
	this->removeChild(player);

	delete player;
}

void Battle::update(float deltaTime)
{

}

