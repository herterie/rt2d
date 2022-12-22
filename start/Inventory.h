/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <rt2d/scene.h>

#include "ActionButton.h"
#include "ItemFrame.h"

 /// @brief The MyScene class is the Scene implementation.
class Inventory : public Scene
{
public:
	int FrameOffset;
	//creating mouse x and y cords
	int mousex;
	int mousey;

	ItemFrame* SelectedFrame;

	bool DropDown;
	/// @brief Constructor
	Inventory();
	/// @brief Destructor
	virtual ~Inventory();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//variabels

	//Vectors for frames
	std::vector<ItemFrame*> Frames;
	std::vector<ItemFrame*> Equipt;

	//frames
	ItemFrame* Frame1;
	ItemFrame* Frame2;
	ItemFrame* Frame3;
	ItemFrame* Frame4;
	ItemFrame* Frame5;
	ItemFrame* Frame6;
	ItemFrame* Frame7;
	ItemFrame* Frame8;
	ItemFrame* Frame9;
	ItemFrame* Frame10;
	ItemFrame* Frame11;
	ItemFrame* Frame12;

	ItemFrame* WeaponFrame;
	ItemFrame* OffHandFrame;
	ItemFrame* HelmFrame;
	ItemFrame* ChestFrame;
	ItemFrame* PantsFrame;
	ItemFrame* BootsFrame;
	ItemFrame* NecklessFrame;
	ItemFrame* RingFrame;
	

	ActionButton* EquipBtn;
	ActionButton* UseBtn;
	ActionButton* DropBtn;
	ActionButton* CancelBtn;
	ActionButton* UnEquipBtn;

	void DropDownMenu(ItemFrame* id, int type);
	void RemoveMenu();
	void EquipItem(ItemFrame* id);
	void UseItem(ItemFrame* id);
	void DropItem(ItemFrame* id);
	void CancelMenu(ItemFrame* id);
	void TakeItem(int id);
	void Unequip(ItemFrame* id);


};

#endif /* INVENTORY_H */
