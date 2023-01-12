/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "ProgressBar.h"


ProgressBar::ProgressBar(int color) : Scene()
{
	this->addSprite("assets/HUD/ProgressBar.tga");

	progressBar = new Sprite;

	progressBar->setupSprite("assets/HUD/ProgressBar.tga", 0.0f, 0.0f, 1.0f, 1.0f);

	switch (color)
	{
	case 0:
		progressBar->color = BLACK;
		break;
	case 1:
		progressBar->color = GREEN;
		break;
	case 2:
		progressBar->color = BLUE;
		break;
	default:
		progressBar->color = BLACK;
		break;
	}

	this->addSprite(progressBar);
}

ProgressBar::~ProgressBar()
{

}

void ProgressBar::update(float deltaTime)
{

}

