/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "ActionButton.h"
#include "myscene.h"

int ButtonIndex = 0;

MyEntity::MyEntity() : Entity()
{
	this->addSprite("assets/ButtonNormal.tga");
}

MyEntity::~MyEntity()
{
	//nothing
}

void MyEntity::update(float deltaTime)
{
	switch (ButtonIndex) {
	case 0:
		this->addSprite("assets/ButtonNormal.tga");
		break;
	case 1:
		this->addSprite("assets/ButtonHover.tga");
		break;
	case 2:
		this->addSprite("assets/ButtonPressed.tga");
		break;
	default:
		this->addSprite("assets/ButtonNormal.tga");
		break;
	}

	if (input()->getKeyDown(KeyCode::Space)) {
		ButtonIndex = 1;
	}
	if (input()->getKeyUp(KeyCode::Space)) {
		ButtonIndex = 0;
	}
}

void MyEntity::Hover() {
	ButtonIndex = 1;
}

void MyEntity::UnHover() {
	ButtonIndex = 0;
}

void MyEntity::Pressed() {
	ButtonIndex = 2;
}