/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "myscene.h"

//creating mouse x and y
int mousex;
int mousey;

MyScene::MyScene() : Scene()
{
	/////////////// Array's ///////////////
	// first bracket is button and second bracket is button cordination,
	ActionBtn[0][0] = -128; // x1
	ActionBtn[0][1] = -64; // y1
	ActionBtn[0][2] = 128; // x2
	ActionBtn[0][3] = 64; // y2	

	/////////////// Timers ///////////////
	// start the timer.
	t.start();

	/////////////// create object ///////////////
	// creating a button and push it in the btn list for the loop
	Button1 = new MyEntity();
	Button1->position = Point2(SWIDTH/2, SHEIGHT/2);
	BtnList.push_back(Button1);

	/////////////// create the scene 'tree' ///////////////
	// add myentity to this Scene as a child.
	this->addChild(Button1);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(Button1);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete Button1;
}

void MyScene::update(float deltaTime)
{
	mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	//check button and mouse collision and press
	for (int i = 0; i < BtnList.size(); i++) {
		if (CheckMouseHover(*BtnList[i])) {
			//hover
			BtnList[i]->Hover();
			if (input()->getMouse(0)) {
				BtnList[i]->Pressed();
			}
		}
		else {
			//unhover
			BtnList[i]->UnHover();
		}
	}
	
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

// check mouse hover over button
bool MyScene::CheckMouseHover(MyEntity& btn) { // AABB - AABB collisiontion.x
	return (mousex < btn.position.x + ActionBtn[0][2] && // player x lesser then enemy x
		mousex > btn.position.x + ActionBtn[0][0] && // player x more then enemy x
		mousey < btn.position.y + ActionBtn[0][3] && // player y lesser then enemy y
		mousey > btn.position.y + ActionBtn[0][1]); // player y more then enemy y
}
