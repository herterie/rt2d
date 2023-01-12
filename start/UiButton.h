/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef UIBUTTON_H
#define UIBUTTON_H

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/entity.h>
#include <rt2d/text.h>


 /// @brief The MyEntity class is the Entity implementation.
class UiButton : public Entity
{
public:
	int mouse_x;
	int mouse_y;
	int SpriteIndex;
	bool Leftpressed;
	/// @brief Constructor
	UiButton(int id);
	/// @brief Destructor
	virtual ~UiButton();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	//check mouse collision
	bool CheckMouseHover();

	void UpdateFrame();



protected:
	std::vector<Text*> text;

private:
	/* add your private declarations */

};

#endif /* UIBUTTON_H */
