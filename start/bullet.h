/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file bullet.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef MYBULLET_H
#define MYBULLET_H

#include <rt2d/entity.h>

 /// @brief The MyEntity class is the Entity implementation.
class MyBullet : public Entity
{
public:
	/// @brief Constructor
	MyBullet();
	/// @brief Destructor
	virtual ~MyBullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	int _guid; ///< @brief The _guid of this Entity
	static int _nextGuid; ///< @brief The _nextGuid of this Entity

private:
	/* add your private declarations */
};

#endif /* MYBULLET_H */
