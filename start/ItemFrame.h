/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ITEMFRAME_H
#define ITEMFRAME_H

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/entity.h>
#include <rt2d/text.h>


 /// @brief The MyEntity class is the Entity implementation.
class ItemFrame : public Entity
{
public:
	int mouse_x;
	int mouse_y;
	int SpriteIndex;
	int ItemCategory;
	bool Rightpressed;
	bool Leftpressed;
	/// @brief Constructor
	ItemFrame(int id);
	/// @brief Destructor
	virtual ~ItemFrame();

	//get mouse x and y
	void Mouse(int x, int y);

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	//check mouse collision
	bool CheckMouseHover();

	void UpdateFrame();
	void ChangeIndex(int id);

	

protected:
	std::vector<Text*> text;

private:
	/* add your private declarations */

};

#endif /* ITEMFRAME_H */
