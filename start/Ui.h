/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef UI_H
#define UI_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class Ui : public Entity
{
public:
	/// @brief Constructor
	Ui();
	/// @brief Destructor
	virtual ~Ui();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	void ShowWaveRound(int wave);

private:
	/* add your private declarations */
	Timer Show;
};

#endif /* MYENTITY_H */
