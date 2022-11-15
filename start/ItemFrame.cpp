/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "ItemFrame.h"
#include "myscene.h"
#include <iostream>


ItemFrame::ItemFrame(int id) : Entity()
{
	pressed = false;
	SpriteIndex = id;
	this->addSprite("assets/ItemFrames/Frame.tga");
	UpdateFrame();
}

ItemFrame::~ItemFrame()
{
	//nothing
}

void ItemFrame::update(float deltaTime)
{
	
	if (CheckMouseHover()) {
		if (input()->getMouseDown(1)) {
			pressed = true;
		}
		else {
			pressed = false;
		}
		
	}
	else {
		pressed = false;
	}
}

void ItemFrame::UpdateFrame() {
	switch (SpriteIndex) {
	case 0:
		this->addSprite("assets/ItemFrames/Frame.tga");
		break;
	case 1:
		this->addSprite("assets/ItemFrames/Item1.tga");
		break;
	case 2:
		this->addSprite("assets/ItemFrames/Item2.tga");
		break;
	case 3:
		this->addSprite("assets/ItemFrames/Item3.tga");
		break;
	default:
		this->addSprite("assets/ItemFrames/Test.tga");
		break;
	}
}


void ItemFrame::Mouse(int x, int y) {
	mouse_x = x;
	mouse_y = y;
}

bool ItemFrame::CheckMouseHover() { // AABB - AABB collision with mouse
	return (mouse_x < this->position.x + 48 && // mouse x lesser then button x2
		mouse_x > this->position.x + -48 && // mouse x lesser then button x1
		mouse_y < this->position.y + 48 && // mouse y lesser then button y2
		mouse_y > this->position.y + -48); // mouse y lesser then button y1
}
