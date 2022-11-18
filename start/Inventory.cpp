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
	DropDown = false;

	mousex = 0;
	mousey = 0;

	FrameOffset = 50;

	//making of drop down menu buttons
	EquipBtn = new ActionButton(0);
	UseBtn = new ActionButton(1);
	DropBtn = new ActionButton(2);
	CancelBtn = new ActionButton(3);

	//equipment frames
	WeaponFrame = new ItemFrame(100);
	WeaponFrame->position.y = 60 + FrameOffset;
	WeaponFrame->position.x = SWIDTH - 60;

	HelmFrame = new ItemFrame(101);
	HelmFrame->position.y = 160 + FrameOffset;
	HelmFrame->position.x = SWIDTH - 60;

	ChestFrame = new ItemFrame(102);
	ChestFrame->position.y = 260 + FrameOffset;
	ChestFrame->position.x = SWIDTH - 60;

	PantsFrame = new ItemFrame(103);
	PantsFrame->position.y = 360 + FrameOffset;
	PantsFrame->position.x = SWIDTH - 60;

	BootsFrame = new ItemFrame(104);
	BootsFrame->position.y = 460 + FrameOffset;
	BootsFrame->position.x = SWIDTH - 60;

	TrinketFrame = new ItemFrame(105);
	TrinketFrame->position.y = 560 + FrameOffset;
	TrinketFrame->position.x = SWIDTH - 60;

	//inventory frames
	Frame1 = new ItemFrame(1);
	Frame1->position.y = 60 + FrameOffset;
	Frame1->position.x = 60;
	Frames.push_back(Frame1);

	Frame2 = new ItemFrame(0);
	Frame2->position.y = 60 + FrameOffset;
	Frame2->position.x = 160;
	Frames.push_back(Frame2);

	Frame3 = new ItemFrame(0);
	Frame3->position.y = 160 + FrameOffset;
	Frame3->position.x = 60;
	Frames.push_back(Frame3);

	Frame4 = new ItemFrame(0);
	Frame4->position.y = 160 + FrameOffset;
	Frame4->position.x = 160;
	Frames.push_back(Frame4);

	Frame5 = new ItemFrame(0);
	Frame5->position.y = 260 + FrameOffset;
	Frame5->position.x = 60;
	Frames.push_back(Frame5);

	Frame6 = new ItemFrame(0);
	Frame6->position.y = 260 + FrameOffset;
	Frame6->position.x = 160;
	Frames.push_back(Frame6);

	Frame7 = new ItemFrame(0);
	Frame7->position.y = 360 + FrameOffset;
	Frame7->position.x = 60;
	Frames.push_back(Frame7);

	Frame8 = new ItemFrame(0);
	Frame8->position.y = 360 + FrameOffset;
	Frame8->position.x = 160;
	Frames.push_back(Frame8);

	Frame9 = new ItemFrame(0);
	Frame9->position.y = 460 + FrameOffset;
	Frame9->position.x = 60;
	Frames.push_back(Frame9);

	Frame10 = new ItemFrame(0);
	Frame10->position.y = 460 + FrameOffset;
	Frame10->position.x = 160;
	Frames.push_back(Frame10);

	Frame11 = new ItemFrame(0);
	Frame11->position.y = 560 + FrameOffset;
	Frame11->position.x = 60;
	Frames.push_back(Frame11);

	Frame12 = new ItemFrame(0);
	Frame12->position.y = 560 + FrameOffset;
	Frame12->position.x = 160;
	Frames.push_back(Frame12);

	//add equipment frames
	this->addChild(WeaponFrame);
	this->addChild(HelmFrame);
	this->addChild(ChestFrame);
	this->addChild(PantsFrame);
	this->addChild(BootsFrame);
	this->addChild(TrinketFrame);

	// add inventory frames
	this->addChild(Frame1);
	this->addChild(Frame2);
	this->addChild(Frame3);
	this->addChild(Frame4);
	this->addChild(Frame5);
	this->addChild(Frame6);
	this->addChild(Frame7);
	this->addChild(Frame8);
	this->addChild(Frame9);
	this->addChild(Frame10);
	this->addChild(Frame11);
	this->addChild(Frame12);
}


Inventory::~Inventory()
{
	for (int i = 0; i < Frames.size(); i++) {
		if (Frames[i] != nullptr) {
			Frames[i] = nullptr;
			delete Frames[i];
		}
		else {
			this->removeChild(Frames[i]);
			delete Frames[i];
		}
	}

	this->removeChild(WeaponFrame);
	this->removeChild(HelmFrame);
	this->removeChild(ChestFrame);
	this->removeChild(PantsFrame);
	this->removeChild(BootsFrame);
	this->removeChild(TrinketFrame);

	delete WeaponFrame;
	delete HelmFrame;
	delete ChestFrame;
	delete PantsFrame;
	delete BootsFrame;
	delete TrinketFrame;
						
}

void Inventory::update(float deltaTime)
{
	mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	Frame1->Mouse(mousex, mousey);
	Frame2->Mouse(mousex, mousey);
	Frame3->Mouse(mousex, mousey);
	Frame4->Mouse(mousex, mousey);

	for (int i = 0; i < Frames.size(); i++) {
		Frames[i]->Mouse(mousex, mousey);
	}

	for (int i = 0; i < Frames.size(); i++) {
		if (Frames[i]->Rightpressed) {
			DropDownMenu();
			std::cout << i << std::endl;
		}
	}

	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	if (DropDown == true) {
		EquipBtn->Mouse(mousex, mousey);
		UseBtn->Mouse(mousex, mousey);
		DropBtn->Mouse(mousex, mousey);
		CancelBtn->Mouse(mousex, mousey);

		if (EquipBtn->pressed) {
			std::cout << "Equip" << std::endl;
			std::cout << "screen x: " << SWIDTH << std::endl;
			std::cout << "screen y: " << SHEIGHT << std::endl;
		}
		if (UseBtn->pressed) {
			std::cout << "Use" << std::endl;
		}
		if (DropBtn->pressed) {
			std::cout << "Drop" << std::endl;
		}
		if (CancelBtn->pressed) {
			std::cout << "Cancel" << std::endl;
		}
	}
}

void Inventory::DropDownMenu() {
	if (DropDown == false) {
		EquipBtn->position.y = mousey + 32;
		EquipBtn->position.x = mousex + 64;

		UseBtn->position.y = mousey + 96;
		UseBtn->position.x = mousex + 64;

		DropBtn->position.y = mousey + 160;
		DropBtn->position.x = mousex + 64;

		CancelBtn->position.y = mousey + 224;
		CancelBtn->position.x = mousex + 64;

		this->addChild(EquipBtn);
		this->addChild(UseBtn);
		this->addChild(DropBtn);
		this->addChild(CancelBtn);
		DropDown = true;
	}
	else {
		this->removeChild(EquipBtn);
		this->removeChild(UseBtn);
		this->removeChild(DropBtn);
		this->removeChild(CancelBtn);
		DropDown = false;
	}
}

