/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "ActionButton.h"
#include "myscene.h"
#include <iostream>


ActionButton::ActionButton(int txtid) : Entity()
{
	pressed = false;

	this->addSprite("assets/ButtonNormal.tga");
	Text* line = new Text();
	line->position.x -= 32;
	line->scale = Point2(0.5f, 0.5f);
	text.push_back(line);
	this->addChild(line);

	TextIndex = txtid;
}

ActionButton::~ActionButton()
{
	//nothig
}

void ActionButton::update(float deltaTime)
{
	switch (TextIndex) {
	case 0:
		text[0]->message("case 1");
		break;
	case 1:
		text[0]->message("case 2");
		break;
	case 2:
		text[0]->message("case 3");
		break;
	default:
		text[0]->message("okay");
		break;
	}

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


void ActionButton::Mouse(int x, int y) {
	mouse_x = x;
	mouse_y = y;
}

bool ActionButton::CheckMouseHover() { // AABB - AABB collision with mouse
	return (mouse_x < position.x + 128 && // mouse x lesser then button x2
		mouse_x > position.x + -128 && // mouse x lesser then button x1
		mouse_y < position.y + 64 && // mouse y lesser then button y2
		mouse_y > position.y + -64); // mouse y lesser then button y1
}