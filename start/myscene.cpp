/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <jj.schot@student.alfa-college.nl>
 */

#include <fstream>
#include <sstream>
#include <vector>
#include "myscene.h"


MyScene::MyScene() : Scene()
{
	mousex = 0;
	mousey = 0;

	Button1 = new ActionButton(0);
	Button1->position.y = SHEIGHT / 4;
	Button1->position.x = SWIDTH / 2;
	BtnList.push_back(Button1);

	Button2 = new ActionButton(1);
	Button2->position.y = SHEIGHT / 2;
	Button2->position.x = SWIDTH / 2;
	BtnList.push_back(Button2);
	
	this->addChild(Button1);
	this->addChild(Button2);
}

MyScene::~MyScene()
{
	this->removeChild(Button1);
	this->removeChild(Button2);

	delete Button1;
	delete Button2;
}

void MyScene::update(float deltaTime)
{
	mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);
	
	Button1->Mouse(mousex, mousey);
	Button2->Mouse(mousex, mousey);
	
	if (Button1->pressed) {
		std::cout << "1" << std::endl;
	}
	if (Button2->pressed) {
		std::cout << "2" << std::endl;
	}

	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

