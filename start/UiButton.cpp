/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "UiButton.h"
#include "myscene.h"
#include <iostream>


UiButton::UiButton(int id) : Entity()
{
	Leftpressed = false;
	SpriteIndex = id;
	UpdateFrame();
}

UiButton::~UiButton()
{
	//nothing
}

void UiButton::update(float deltaTime)
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

void UiButton::UpdateFrame() {
	switch (SpriteIndex) {
	case 0:
		this->addSprite("assets/HUD/BackpackIcon.tga");
		break;
	case 1:
		this->addSprite("assets/HUD/SettingsIcon.tga");
		break;
	case 2:
		this->addSprite("assets/HUD/EquipmentIcon.tga");
		break;
	default:
		this->addSprite("assets/HUD/SettingsIcon.tga");
		break;
	}
}

bool UiButton::CheckMouseHover() { // AABB - AABB collision with mouse
	int mouse_x = input()->getMouseX();
	int mouse_y = input()->getMouseY();
	return (mouse_x < this->position.x + 48 && // mouse x lesser then button x2
		mouse_x > this->position.x + -48 && // mouse x lesser then button x1
		mouse_y < this->position.y + 48 && // mouse y lesser then button y2
		mouse_y > this->position.y + -48); // mouse y lesser then button y1
}
