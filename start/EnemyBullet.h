/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file bullet.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <rt2d/entity.h>

 /// @brief The MyEntity class is the Entity implementation.
class EnemyBullet : public Entity
{
public:
	/// @brief Constructor
	EnemyBullet();
	/// @brief Destructor
	virtual ~EnemyBullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* STINGER_H */
