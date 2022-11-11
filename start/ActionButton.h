/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYENTITY_H
#define MYENTITY_H

#include <rt2d/scene.h>
#include <rt2d/entity.h>


/// @brief The MyEntity class is the Entity implementation.
class MyEntity : public Entity
{
public:
	/// @brief Constructor
	MyEntity();
	/// @brief Destructor
	virtual ~MyEntity();

	void Hover();
	void UnHover();
	void Pressed();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYENTITY_H */
