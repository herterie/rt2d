/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Ui.h"


Ui::Ui() : Entity()
{
	
}

Ui::~Ui()
{

}

void Ui::update(float deltaTime)
{
	if (Show.seconds() >= 1) {
		this->addSprite("Assets/EmptyWave.tga");
	}
}

void Ui::ShowWaveRound(int wave)
{
	Show.start();
	this->position.x = SWIDTH / 2;
	this->position.y = SHEIGHT / 2;
	this->scale.x *= -1;
	this->scale.y *= -1;

	switch (wave)
	{
	default:
		this->addSprite("Assets/EmptyWave.tga");
		break;
	case 1:
		this->addSprite("Assets/WavesText1.tga");
		break;
	case 2:
		this->addSprite("Assets/WavesText2.tga");
		break;
	case 3:
		this->addSprite("Assets/WavesText3.tga");
		break;
	case 4:
		this->addSprite("Assets/WavesText4.tga");
		break;
	case 5:
		this->addSprite("Assets/WavesText5.tga");
		break;
	case 6:
		this->addSprite("Assets/WavesText6.tga");
		break;
	case 7:
		this->addSprite("Assets/WavesText7.tga");
		break;
	case 8:
		this->addSprite("Assets/WavesText8.tga");
		break;
	}
}