/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Abilitie.h"
#include "myscene.h"
#include <iostream>

Abilitie::Abilitie(int id) : Entity()
{
	Pressed = false;
	SpriteIndex = id;
	this->addSprite("assets/AbilitieIcons/AbilitieIcon1.tga");
	UpdateFrame();
}

Abilitie::~Abilitie()
{
	//nothing
}

void Abilitie::update(float deltaTime)
{

	if (CheckMouseHover()) {
		if (input()->getMouseDown(0)) {
			Pressed = true;
		}
		else {
			Pressed = false;
		}
	}
	else {
		Pressed = false;
	}
}

void Abilitie::UpdateFrame() {
	switch (SpriteIndex) {
	case 0:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon1.tga");
		break;
	case 1:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon2.tga");
		break;
	case 2:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon3.tga");
		break;
	case 3:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon4.tga");
		break;
	case 4:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon5.tga");
		break;
	case 5:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon6.tga");
		break;
	case 6:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon7.tga");
		break;
	case 7:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon8.tga");
		break;
	case 8:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon9.tga");
		break;
	case 9:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon10.tga");
		break;
	default:
		this->addSprite("assets/AbilitieIcons/AbilitieIcon1.tga");
		break;
	}
}

void Abilitie::ChangeIndex(int id) {
	SpriteIndex = id;
	UpdateFrame();
}


bool Abilitie::CheckMouseHover() { // AABB - AABB collision with mouse
	int mouse_x = input()->getMouseX();
	int mouse_y = input()->getMouseY();
	return (mouse_x < this->position.x + 48 && // mouse x lesser then button x2
		mouse_x > this->position.x + -48 && // mouse x lesser then button x1
		mouse_y < this->position.y + 48 && // mouse y lesser then button y2
		mouse_y > this->position.y + -48); // mouse y lesser then button y1
}
