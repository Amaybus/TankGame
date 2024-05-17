#pragma once
#include "TankPlayer.h"
#include "Turret.h"
#include "Bullet.h"
#include "Obstacle.h"
#include "AABB.h"

#include "SpriteObject.h"
#include "Matrix3.h"

#include <vector>
#include <iostream>

class Game
{
public:
	void Init();
	void Update(float deltaTime, float screenWidth, float screenHeight);
	void Draw();
	void Shutdown();

	TankPlayer* player;
	Turret* turret;
	Bullet* bullet;
	Obstacle* obstacle;

	std::vector<GameObject*> gameObjects;
	std::vector<AABB> collisionObjs;
	std::vector<GameObject*> toDelete;
};
