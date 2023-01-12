/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <rt2d/scene.h>

 /// @brief The MyScene class is the Scene implementation.
class ProgressBar : public Scene
{
public:
	Sprite* progressBar;
	/// @brief Constructor
	ProgressBar(int color);
	/// @brief Destructor
	virtual ~ProgressBar();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	//variabels
};

#endif /* PROGRESSBAR_H */
