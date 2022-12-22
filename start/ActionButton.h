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
	ActionButton(std::string buttontext);
	/// @brief Destructor
	virtual ~ActionButton();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	//check mouse collision
	bool CheckMouseHover();

	bool pressed;

protected:


private:
	/* add your private declarations */
	Text* line;
	
};

#endif /* ACTIONBUTTON_H */
