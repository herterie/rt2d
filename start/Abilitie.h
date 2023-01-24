/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ABILITIE_H
#define ABILITIE_H

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/entity.h>
#include <rt2d/text.h>


 /// @brief The MyEntity class is the Entity implementation.
class Abilitie : public Entity
{
public:
	int mouse_x;
	int mouse_y;
	int SpriteIndex;
	bool Pressed;
	/// @brief Constructor
	Abilitie(int id);
	/// @brief Destructor
	virtual ~Abilitie();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	//check mouse collision
	bool CheckMouseHover();

	void UpdateFrame();
	void ChangeIndex(int id);



protected:


private:
	/* add your private declarations */

};

#endif /* ABILITIE_H */
