/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "ItemFrame.h"
#include "myscene.h"
#include <iostream>

enum {
	NOTHING,
	WEAPON,
	OFF_HAND,
	HELMET,
	CHEST,
	PANTS,
	BOOTS,
	NECKLESS,
	RING
};

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
	7 = neckless
	8 = ring
	9 = usable
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
		ItemCategory = 2;
		break;
	case 5:
		this->addSprite("assets/ItemFrames/Item5.tga");
		ItemCategory = 2;
		break;
	case 6:
		this->addSprite("assets/ItemFrames/Item6.tga");
		ItemCategory = 2;
		break;
	case 7:
		this->addSprite("assets/ItemFrames/Item7.tga");
		ItemCategory = 3;
		break;
	case 8:
		this->addSprite("assets/ItemFrames/Item8.tga");
		ItemCategory = 3;
		break;
	case 9:
		this->addSprite("assets/ItemFrames/Item9.tga");
		ItemCategory = 3;
		break;
	case 10:
		this->addSprite("assets/ItemFrames/Item10.tga");
		ItemCategory = 4;
		break;
	case 11:
		this->addSprite("assets/ItemFrames/Item11.tga");
		ItemCategory = 4;
		break;
	case 12:
		this->addSprite("assets/ItemFrames/Item12.tga");
		ItemCategory = 4;
		break;
	case 13:
		this->addSprite("assets/ItemFrames/Item13.tga");
		ItemCategory = 5;
		break;
	case 14:
		this->addSprite("assets/ItemFrames/Item14.tga");
		ItemCategory = 5;
		break;
	case 15:
		this->addSprite("assets/ItemFrames/Item15.tga");
		ItemCategory = 5;
		break;
	case 16:
		this->addSprite("assets/ItemFrames/Item16.tga");
		ItemCategory = 6;
		break;
	case 17:
		this->addSprite("assets/ItemFrames/Item17.tga");
		ItemCategory = 6;
		break;
	case 18:
		this->addSprite("assets/ItemFrames/Item18.tga");
		ItemCategory = 6;
		break;
	case 19:
		this->addSprite("assets/ItemFrames/Item19.tga");
		ItemCategory = 7;
		break;
	case 20:
		this->addSprite("assets/ItemFrames/Item20.tga");
		ItemCategory = 7;
		break;
	case 21:
		this->addSprite("assets/ItemFrames/Item21.tga");
		ItemCategory = 7;
		break;
	case 22:
		this->addSprite("assets/ItemFrames/Item22.tga");
		ItemCategory = 8;
		break;
	case 23:
		this->addSprite("assets/ItemFrames/Item23.tga");
		ItemCategory = 8;
		break;
	case 24:
		this->addSprite("assets/ItemFrames/Item24.tga");
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


bool ItemFrame::CheckMouseHover() { // AABB - AABB collision with mouse
	int mouse_x = input()->getMouseX();
	int mouse_y = input()->getMouseY();
	return (mouse_x < this->position.x + 48 && // mouse x lesser then button x2
		mouse_x > this->position.x + -48 && // mouse x lesser then button x1
		mouse_y < this->position.y + 48 && // mouse y lesser then button y2
		mouse_y > this->position.y + -48); // mouse y lesser then button y1
}
