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
	Armor = 0;
	Strenght = 0;
	Dexterity = 0;
	Intellect = 0;
	luck = 0;

	DropDown = false;
	SelectedFrame = nullptr;

	mousex = 0;
	mousey = 0;

	FrameOffset = 50;

	ArmorTxt = new Text();
	ArmorTxt->position.y = SHEIGHT - 280;
	ArmorTxt->position.x = SWIDTH - 188;
	ArmorTxt->scale = Point2(0.7f, 0.7f);
	ArmorTxt->message("Armor: " + std::to_string(Armor));

	StrenghtTxt = new Text();
	StrenghtTxt->position.y = SHEIGHT - 250;
	StrenghtTxt->position.x = SWIDTH - 188;
	StrenghtTxt->scale = Point2(0.7f, 0.7f);
	StrenghtTxt->message("STR: " + std::to_string(Strenght));

	DexterityTxt = new Text();
	DexterityTxt->position.y = SHEIGHT - 220;
	DexterityTxt->position.x = SWIDTH - 188;
	DexterityTxt->scale = Point2(0.7f, 0.7f);
	DexterityTxt->message("DEX: " + std::to_string(Dexterity));

	IntellectTxt = new Text();
	IntellectTxt->position.y = SHEIGHT - 190;
	IntellectTxt->position.x = SWIDTH - 188;
	IntellectTxt->scale = Point2(0.7f, 0.7f);
	IntellectTxt->message("INT: " + std::to_string(Intellect));

	luckTxt = new Text();
	luckTxt->position.y = SHEIGHT - 160;
	luckTxt->position.x = SWIDTH - 188;
	luckTxt->scale = Point2(0.7f, 0.7f);
	luckTxt->message("Luck: " + std::to_string(luck));


	//making of drop down menu buttons
	EquipBtn = new ActionButton("Equip");
	UseBtn = new ActionButton("Use");
	DropBtn = new ActionButton("Drop");
	CancelBtn = new ActionButton("Cancel");
	UnEquipBtn = new ActionButton("Unequip");

	EquipBtn->position.y = -400;
	EquipBtn->position.x = -400;

	UseBtn->position.y = -400;
	UseBtn->position.x = -400;

	DropBtn->position.y = -400;
	DropBtn->position.x = -400;

	CancelBtn->position.y = -400;
	CancelBtn->position.x = -400;

	UnEquipBtn->position.y = -400;
	UnEquipBtn->position.x = -400;

	//equipment frames
	WeaponFrame = new ItemFrame(100);
	WeaponFrame->position.y = 60;
	WeaponFrame->position.x = SWIDTH - 160;
	Equipt.push_back(WeaponFrame);

	OffHandFrame = new ItemFrame(101);
	OffHandFrame->position.y = 60;
	OffHandFrame->position.x = SWIDTH - 60;
	Equipt.push_back(OffHandFrame);

	HelmFrame = new ItemFrame(102);
	HelmFrame->position.y = 260;
	HelmFrame->position.x = SWIDTH - 160;
	Equipt.push_back(HelmFrame);

	ChestFrame = new ItemFrame(103);
	ChestFrame->position.y = 260;
	ChestFrame->position.x = SWIDTH - 60;
	Equipt.push_back(ChestFrame);

	PantsFrame = new ItemFrame(104);
	PantsFrame->position.y = 160;
	PantsFrame->position.x = SWIDTH - 160;
	Equipt.push_back(PantsFrame);

	BootsFrame = new ItemFrame(105);
	BootsFrame->position.y = 160;
	BootsFrame->position.x = SWIDTH - 60;
	Equipt.push_back(BootsFrame);

	RingFrame = new ItemFrame(106);
	RingFrame->position.y = 360;
	RingFrame->position.x = SWIDTH - 60;
	Equipt.push_back(RingFrame);

	NecklessFrame = new ItemFrame(107);
	NecklessFrame->position.y = 360;
	NecklessFrame->position.x = SWIDTH - 160;
	Equipt.push_back(NecklessFrame);

	//inventory frames
	Frame1 = new ItemFrame(3);
	Frame1->position.y = 60 + FrameOffset;
	Frame1->position.x = 60;
	Frames.push_back(Frame1);

	Frame2 = new ItemFrame(6);
	Frame2->position.y = 60 + FrameOffset;
	Frame2->position.x = 160;
	Frames.push_back(Frame2);

	Frame3 = new ItemFrame(9);
	Frame3->position.y = 160 + FrameOffset;
	Frame3->position.x = 60;
	Frames.push_back(Frame3);

	Frame4 = new ItemFrame(12);
	Frame4->position.y = 160 + FrameOffset;
	Frame4->position.x = 160;
	Frames.push_back(Frame4);

	Frame5 = new ItemFrame(15);
	Frame5->position.y = 260 + FrameOffset;
	Frame5->position.x = 60;
	Frames.push_back(Frame5);

	Frame6 = new ItemFrame(18);
	Frame6->position.y = 260 + FrameOffset;
	Frame6->position.x = 160;
	Frames.push_back(Frame6);

	Frame7 = new ItemFrame(21);
	Frame7->position.y = 360 + FrameOffset;
	Frame7->position.x = 60;
	Frames.push_back(Frame7);

	Frame8 = new ItemFrame(24);
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

	//add text 
	this->addChild(ArmorTxt);
	this->addChild(StrenghtTxt);
	this->addChild(DexterityTxt);
	this->addChild(IntellectTxt);
	this->addChild(luckTxt);

	//add equipment frames
	this->addChild(WeaponFrame);
	this->addChild(OffHandFrame);
	this->addChild(HelmFrame);
	this->addChild(ChestFrame);
	this->addChild(PantsFrame);
	this->addChild(BootsFrame);
	this->addChild(RingFrame);
	this->addChild(NecklessFrame);

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

	// drop menu buttons
	this->addChild(EquipBtn);
	this->addChild(DropBtn);
	this->addChild(CancelBtn);
	this->addChild(UseBtn);
	this->addChild(UnEquipBtn);
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

	for (int i = 0; i < Equipt.size(); i++) {
		if (Equipt[i] != nullptr) {
			Equipt[i] = nullptr;
			delete Equipt[i];
		}
		else {
			this->removeChild(Equipt[i]);
			delete Equipt[i];
		}
	}
						
}

void Inventory::update(float deltaTime)
{
	mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);

	for (int i = 0; i < Frames.size(); i++) {
		if (Frames[i]->Rightpressed) {
			if (Frames[i]->ItemCategory != 0) {
				SelectedFrame = Frames[i];
				DropDownMenu(Frames[i], 0);
			}
		}
	}

	for (int i = 0; i < Equipt.size(); i++) {
		if (Equipt[i]->Rightpressed) {
			if (Equipt[i]->ItemCategory != 0) {
				SelectedFrame = Equipt[i];
				DropDownMenu(Equipt[i], 1);
			}
		}
	}	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	if (DropDown == true) {
		if (EquipBtn->pressed) {
			EquipItem(SelectedFrame);
		}
		if (UseBtn->pressed) {
			UseItem(SelectedFrame);
		}
		if (DropBtn->pressed) {
			DropItem(SelectedFrame);
		}
		if (CancelBtn->pressed) {
			CancelMenu(SelectedFrame);
		}
		if (UnEquipBtn->pressed) {
			Unequip(SelectedFrame);
		}
	}
	ChangeStats();
}

void Inventory::DropDownMenu(ItemFrame* id, int type) {
	if (DropDown == false) {
		if (id->ItemCategory != 9 && type == 0) {
			if (mousex >= SWIDTH - 64) {
				EquipBtn->position.y = mousey - 32;
				EquipBtn->position.x = mousex - 64;

				DropBtn->position.y = mousey - 96;
				DropBtn->position.x = mousex - 64;

				CancelBtn->position.y = mousey - 160;
				CancelBtn->position.x = mousex - 64;
			}
			else {
				EquipBtn->position.y = mousey + 32;
				EquipBtn->position.x = mousex + 64;

				DropBtn->position.y = mousey + 96;
				DropBtn->position.x = mousex + 64;

				CancelBtn->position.y = mousey + 160;
				CancelBtn->position.x = mousex + 64;
			}
			DropDown = true;
		}
		else if (id->ItemCategory == 9 && type == 0) {
			UseBtn->position.y = mousey + 32;
			UseBtn->position.x = mousex + 64;

			DropBtn->position.y = mousey + 96;
			DropBtn->position.x = mousex + 64;

			CancelBtn->position.y = mousey + 160;
			CancelBtn->position.x = mousex + 64;
			DropDown = true;
		}
		if  (type == 1) {
			if (mousex >= SWIDTH - 128) {
				UnEquipBtn->position.y = mousey + 32;
				UnEquipBtn->position.x = mousex - 64;

				DropBtn->position.y = mousey + 96;
				DropBtn->position.x = mousex - 64;

				CancelBtn->position.y = mousey + 160;
				CancelBtn->position.x = mousex - 64;
			}
			else {
				UnEquipBtn->position.y = mousey + 32;
				UnEquipBtn->position.x = mousex + 64;

				DropBtn->position.y = mousey + 96;
				DropBtn->position.x = mousex + 64;

				CancelBtn->position.y = mousey + 160;
				CancelBtn->position.x = mousex + 64;
			}
			DropDown = true;
		}
		
	}else {
		RemoveMenu();
	}
}

void Inventory::RemoveMenu() {
	DropDown = false;
	EquipBtn->position.y = -400;
	EquipBtn->position.x = -400;

	UseBtn->position.y = -400;
	UseBtn->position.x = -400;

	DropBtn->position.y = -400;
	DropBtn->position.x = -400;

	CancelBtn->position.y = -400;
	CancelBtn->position.x = -400;

	UnEquipBtn->position.y = -400;
	UnEquipBtn->position.x = -400;
}

void Inventory::EquipItem(ItemFrame* id) {
	if (id->ItemCategory == 1) {
		if (WeaponFrame->SpriteIndex != 100){
			int oldEquipment = WeaponFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			WeaponFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			WeaponFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	if (id->ItemCategory == 2) {
		if (OffHandFrame->SpriteIndex != 101) {
			int oldEquipment = OffHandFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			OffHandFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			OffHandFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	if (id->ItemCategory == 3) {
		if (HelmFrame->SpriteIndex != 102) {
			int oldEquipment = HelmFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			HelmFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			HelmFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	if (id->ItemCategory == 4) {
		if (ChestFrame->SpriteIndex != 103) {
			int oldEquipment = ChestFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			ChestFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			ChestFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	if (id->ItemCategory == 5) {
		if (PantsFrame->SpriteIndex != 104) {
			int oldEquipment = PantsFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			PantsFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			PantsFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	if (id->ItemCategory == 6) {
		if (BootsFrame->SpriteIndex != 105) {
			int oldEquipment = BootsFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			BootsFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			BootsFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	if (id->ItemCategory == 7) {
		if (NecklessFrame->SpriteIndex != 107) {
			int oldEquipment = NecklessFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			NecklessFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			NecklessFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	if (id->ItemCategory == 8) {
		if (RingFrame->SpriteIndex != 106) {
			int oldEquipment = RingFrame->SpriteIndex;
			int newEquipment = id->SpriteIndex;
			RingFrame->ChangeIndex(newEquipment);
			id->ChangeIndex(oldEquipment);
		}
		else {
			RingFrame->ChangeIndex(id->SpriteIndex);
			id->ChangeIndex(0);
		}
	}
	RemoveMenu();
}

void Inventory::TakeItem(int id) {
	for (int i = 0; i < Frames.size(); i++) {
		if (Frames[i]->SpriteIndex == 0) {
			Frames[i]->ChangeIndex(id);
			break;
		}
	}

}

void Inventory::Unequip(ItemFrame* id) {
	TakeItem(id->SpriteIndex);
	if (SelectedFrame == WeaponFrame) {
		WeaponFrame->ChangeIndex(100);
	}
	if (SelectedFrame == OffHandFrame) {
		OffHandFrame->ChangeIndex(101);
	}
	if (SelectedFrame == HelmFrame) {
		HelmFrame->ChangeIndex(102);
	}
	if (SelectedFrame == ChestFrame) {
		ChestFrame->ChangeIndex(103);
	}
	if (SelectedFrame == PantsFrame) {
		PantsFrame->ChangeIndex(104);
	}
	if (SelectedFrame == BootsFrame) {
		BootsFrame->ChangeIndex(105);
	}
	if (SelectedFrame == NecklessFrame) {
		NecklessFrame->ChangeIndex(107);
	}
	if (SelectedFrame == RingFrame) {
		RingFrame->ChangeIndex(106);
	}
	RemoveMenu();
}

void Inventory::UseItem(ItemFrame* id) {
	std::cout << "Use" << std::endl;
}

void Inventory::DropItem(ItemFrame* id) {
	if (id == WeaponFrame) {
		id->ChangeIndex(100);
	}else if (SelectedFrame == OffHandFrame) {
		OffHandFrame->ChangeIndex(101);
	}else if (SelectedFrame == HelmFrame) {
		HelmFrame->ChangeIndex(102);
	}else if (SelectedFrame == ChestFrame) {
		ChestFrame->ChangeIndex(103);
	}else if (SelectedFrame == PantsFrame) {
		PantsFrame->ChangeIndex(104);
	}else if (SelectedFrame == BootsFrame) {
		BootsFrame->ChangeIndex(105);
	}else if (SelectedFrame == NecklessFrame) {
		NecklessFrame->ChangeIndex(107);
	}else if (SelectedFrame == RingFrame) {
		RingFrame->ChangeIndex(106);
	}else {
		id->ChangeIndex(0);
	}
	RemoveMenu();
}

void Inventory::CancelMenu(ItemFrame* id) {
	RemoveMenu();
	
}

void Inventory::ChangeStats() {
	Armor = 0;
	Strenght = 0;
	Dexterity = 0;
	Intellect = 0;
	luck = 0;
	for (int i = 0; i < Equipt.size(); i++) {
		switch (Equipt[i]->SpriteIndex)
		{
		case 1:
			Strenght += 5;
			break;
		case 2:
			Dexterity += 7;
			break;
		case 3:
			Intellect += 5;
			break;
		case 4:
			Armor += 3;
			break;
		case 5:
			Dexterity += 3;
			break;
		case 6:
			Intellect += 3;
			break;
		case 7:
			Armor += 3;
			Strenght += 1;
			break;
		case 8:
			Armor += 2;
			Dexterity += 1;
			break;
		case 9:
			Armor += 1;
			Intellect += 3;
			break;
		case 10:
			Armor += 3;
			Strenght += 1;
			break;
		case 11:
			Armor += 2;
			Dexterity += 1;
			break;
		case 12:
			Armor += 1;
			Intellect += 3;
			break;
		case 13:
			Armor += 3;
			Strenght += 1;
			break;
		case 14:
			Armor += 2;
			Dexterity += 1;
			break;
		case 15:
			Armor += 1;
			Intellect += 3;
			break;
		case 16:
			Armor += 3;
			Strenght += 1;
			break;
		case 17:
			Armor += 2;
			Dexterity += 1;
			break;
		case 18:
			Armor += 1;
			Intellect += 3;
			break;
		case 19:
			Strenght += 3;
			break;
		case 20:
			Dexterity += 3;
			break;
		case 21:
			Intellect += 3;
			break;
		case 22:
			Strenght += 3;
			break;
		case 23:
			Dexterity += 3;
			break;
		case 24:
			Intellect += 3;
			break;
		default:
			break;
		}
	}
	ArmorTxt->message("Armor: " + std::to_string(Armor));
	StrenghtTxt->message("STR: " + std::to_string(Strenght));
	DexterityTxt->message("DEX: " + std::to_string(Dexterity));
	IntellectTxt->message("INT: " + std::to_string(Intellect));
	luckTxt->message("Luck: " + std::to_string(luck));
}