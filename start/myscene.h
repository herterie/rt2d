/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>

#include "Player.h"
#include "bullet.h"
#include "SpaceBee.h"
#include "EnemyBullet.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief Player 
	Player* myentity;

	/// @brief Enemy
	SpaceBee* spacebee;
	SpaceBee* spacebee1;
	EnemyBullet* stinger;

	/// @brief Timers
	Timer t;
	Timer BulletReloadTimer;
	Timer AttaskSpeed;

};

#endif /* SCENE00_H */
