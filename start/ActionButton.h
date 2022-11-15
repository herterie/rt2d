/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/entity.h>
#include <rt2d/text.h>


/// @brief The MyEntity class is the Entity implementation.
class ActionButton : public Entity
{
public:
	/// @brief Constructor
	ActionButton(int txtid);
	/// @brief Destructor
	virtual ~ActionButton();

	//get mouse x and y
	void Mouse(int x, int y);

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	//check mouse collision
	bool CheckMouseHover();

	int mouse_x;
	int mouse_y;
	int TextIndex;
	bool pressed;

protected:
	std::vector<Text*> text;

private:
	/* add your private declarations */
	
};

#endif /* ACTIONBUTTON_H */
