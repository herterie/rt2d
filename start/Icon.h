/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef ICON_H
#define ICON_H

#include <rt2d/scene.h>

 /// @brief The MyScene class is the Scene implementation.
class Icon : public Scene
{
public:
	/// @brief Constructor
	Icon();
	/// @brief Destructor
	virtual ~Icon();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//variabels
};

#endif /* ICON_H */
