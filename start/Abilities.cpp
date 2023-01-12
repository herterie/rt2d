/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "Abilities.h"
#include "myscene.h"
#include <iostream>


Abilities::Abilities(int id) : Entity()
{
	Leftpressed = false;
	SpriteIndex = id;
	UpdateFrame();
}

Abilities::~Abilities()
{
	//nothing
}

void Abilities::update(float deltaTime)
{

	if (CheckMouseHover()) {
		if (input()->getMouseDown(0)) {
			Leftpressed = true;
		}
		else {
			Leftpressed = false;
		}
	}
	else {
		Leftpressed = false;
	}
}

void Abilities::UpdateFrame() {
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

bool Abilities::CheckMouseHover() { // AABB - AABB collision with mouse
	int mouse_x = input()->getMouseX();
	int mouse_y = input()->getMouseY();
	return (mouse_x < this->position.x + 48 && // mouse x lesser then button x2
		mouse_x > this->position.x + -48 && // mouse x lesser then button x1
		mouse_y < this->position.y + 48 && // mouse y lesser then button y2
		mouse_y > this->position.y + -48); // mouse y lesser then button y1
}
