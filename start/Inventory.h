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
	//creating mouse x and y cords
	int mousex;
	int mousey;
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

	//frames
	ItemFrame* Frame1;
	ItemFrame* Frame2;
	ItemFrame* Frame3;
	ItemFrame* Frame4;

	void DropDownMenu();


};

#endif /* INVENTORY_H */
