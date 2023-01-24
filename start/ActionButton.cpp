/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "ActionButton.h"
#include "myscene.h"
#include <iostream>


ActionButton::ActionButton(std::string buttontext) : Entity()
{
	pressed = false;
	this->scale.x = 0.5;
	this->scale.y = 0.5;

	this->addSprite("assets/ButtonNormal.tga");
	Text* line = new Text();
	line->position.x -= 32;
	line->scale = Point2(0.5f, 0.5f);
	line->message(buttontext);
	this->addChild(line);
}

ActionButton::~ActionButton()
{
	//nothig
}

void ActionButton::update(float deltaTime)
{
	if (CheckMouseHover()) {
		if (input()->getMouseDown(0)) {
			this->addSprite("assets/ButtonPressed.tga");
			pressed = true;
		}
		else {
			this->addSprite("assets/ButtonHover.tga");
			pressed = false;
		}
	}
	else {
		this->addSprite("assets/ButtonNormal.tga");
		pressed = false;
	}
}

bool ActionButton::CheckMouseHover() { // AABB - AABB collision with mouse
	int mouse_x = input()->getMouseX();
	int mouse_y = input()->getMouseY();
	return (mouse_x < position.x + 64 && // mouse x lesser then button x2
		mouse_x > position.x + -64 && // mouse x lesser then button x1
		mouse_y < position.y + 32 && // mouse y lesser then button y2
		mouse_y > position.y + -32); // mouse y lesser then button y1
}