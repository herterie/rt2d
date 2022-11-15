/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "Inventory.h"



Inventory::Inventory() : Scene()
{
	mousex = 0;
	mousey = 0;

	Frame1 = new ItemFrame(0);
	Frame1->position.y = SHEIGHT / 4;
	Frame1->position.x = 60;
	Frames.push_back(Frame1);

	Frame2 = new ItemFrame(1);
	Frame2->position.y = SHEIGHT / 4 + 100;
	Frame2->position.x = 60;
	Frames.push_back(Frame2);

	Frame3 = new ItemFrame(2);
	Frame3->position.y = SHEIGHT / 4;
	Frame3->position.x = 160;
	Frames.push_back(Frame3);

	Frame4 = new ItemFrame(3);
	Frame4->position.y = SHEIGHT / 4 + 100;
	Frame4->position.x = 160;
	Frames.push_back(Frame4);

	//this->addChild(Button1);
	//this->addChild(Button2);
	this->addChild(Frame1);
	this->addChild(Frame2);
	this->addChild(Frame3);
	this->addChild(Frame4);
}


Inventory::~Inventory()
{

	this->removeChild(Frame1);
	this->removeChild(Frame2);
	this->removeChild(Frame3);
	this->removeChild(Frame4);

	delete Frame1;
	delete Frame2;
	delete Frame3;
	delete Frame4;
}

void Inventory::update(float deltaTime)
{
	mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	Frame1->Mouse(mousex, mousey);

	if (Frame1->pressed) {
		std::cout << "3" << std::endl;
	}

	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

void Inventory::DropDownMenu() {

}

