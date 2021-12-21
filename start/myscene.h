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
#include "Ui.h"

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
	//functions
	void removeBullet(MyBullet* bullet);
	void PlaceEnemy();
	void SpawnEnemy(int type);
	bool CheckPlayerToEnemyCollision(Player& pl, SpaceBee& sb);
	bool CheckPbulletToEnemyCollision(MyBullet& pb, SpaceBee& sb);
	bool CheckEbulletToEPlayerCollision(Player& pl, EnemyBullet& eb);


private:
	//variabels
	int Enemies[1][8];  //declaration of enemies 2D array  
	int player[5];  //declaration of player array
	int CurrentRound = 0;
	int backLine;
	bool ShowWaves = false;

	// Vector lists
	std::vector<MyBullet*> BulletList;
	std::vector<SpaceBee*> EnemyList;
	std::vector<EnemyBullet*> EnemyBulletList;
	std::vector<SpaceBee*> BackLine;
	std::vector<SpaceBee*> FrontLine;

	Ui* WaveShow;

	/// @brief Player 
	Player* myentity;

	/// @brief Enemy
	SpaceBee* spacebee;
	EnemyBullet* stinger;

	/// @brief Timers
	Timer EnemyAttackSpeed;
	Timer BulletReloadTimer;
	Timer AttaskSpeed;
	Timer TextTimer;
};

#endif /* SCENE00_H */
