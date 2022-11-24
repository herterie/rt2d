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
	Rightpressed = false;
	SpriteIndex = id;
	ItemCategory = 0; 
	/*
	0 = nothing
	1 = weapon
	2 = off hand
	3 = helmet
	4 = chest
	5 = pants
	6 = boots
	7 = trinket
	8 = usable
	*/
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
			Rightpressed = true;
		}
		else {
			Rightpressed = false;
		}
		if (input()->getMouseDown(0)) {
			Leftpressed = true;
		}
		else {
			Leftpressed = false;
		}
	}
	else {
		Rightpressed = false;
		Leftpressed = false;
	}
}

void ItemFrame::UpdateFrame() {
	switch (SpriteIndex) {
	case 0:
		this->addSprite("assets/ItemFrames/Frame.tga");
		ItemCategory = 0;
		break;
	case 1:
		this->addSprite("assets/ItemFrames/Item1.tga");
		ItemCategory = 1;
		break;
	case 2:
		this->addSprite("assets/ItemFrames/Item2.tga");
		ItemCategory = 1;
		break;
	case 3:
		this->addSprite("assets/ItemFrames/Item3.tga");
		ItemCategory = 1;
		break;
	case 4:
		this->addSprite("assets/ItemFrames/Item4.tga");
		ItemCategory = 8;
		break;
	case 100:
		this->addSprite("assets/ItemFrames/WeaponFrame.tga");
		ItemCategory = 0;
		break;
	case 101:
		this->addSprite("assets/ItemFrames/OffHandFrame.tga");
		ItemCategory = 0;
		break;
	case 102:
		this->addSprite("assets/ItemFrames/HelmFrame.tga");
		ItemCategory = 0;
		break;
	case 103:
		this->addSprite("assets/ItemFrames/ChestFrame.tga");
		ItemCategory = 0;
		break;
	case 104:
		this->addSprite("assets/ItemFrames/PantsFrame.tga");
		ItemCategory = 0;
		break;
	case 105:
		this->addSprite("assets/ItemFrames/BootsFrame.tga");
		ItemCategory = 0;
		break;
	case 106:
		this->addSprite("assets/ItemFrames/RingFrame.tga");
		ItemCategory = 0;
		break;
	case 107:
		this->addSprite("assets/ItemFrames/NecklessFrame.tga");
		ItemCategory = 0;
		break;

	default:
		this->addSprite("assets/ItemFrames/Frame.tga");
		ItemCategory = 0;	
		break;
	}
}

void ItemFrame::ChangeIndex(int id) {
	SpriteIndex = id;
	UpdateFrame();
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
