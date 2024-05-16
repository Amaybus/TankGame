#include "Game.h"

void Game::Init()
{
	player = new TankPlayer;
	turret = new Turret;
	obstacle = new Obstacle;

	obstacleAABB = new AABB;

	turret->SetParent(player);
	obstacleAABB->SetParent(obstacle);
	collisionObjs.push_back(*obstacleAABB);

	gameObjects.push_back(player);
	gameObjects.push_back(obstacle);
}

void Game::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		bullet = new Bullet;
		bulletAABB = new AABB(vec2(50, 50), vec2 (100, 100));
		//bulletAABB->SetParent(bullet);
		collisionObjs.push_back(*bulletAABB);

		gameObjects.push_back(bullet);
		bullet->SetLocalPosition(turret->GetWorldPosition());
 		bullet->SetLocalRotation(turret->GetWorldRotation());
		std::vector<vec2> corners = bulletAABB->Corners();
		DrawCircle(corners[0].x, corners[0].y, 5, RED);
		DrawCircle(corners[1].x, corners[1].y, 5, RED);
		DrawCircle(corners[2].x, corners[2].y, 5, RED);
		DrawCircle(corners[3].x, corners[3].y, 5, RED);
	}
	
	bullet->DestructBullet(GetScreenWidth(), GetScreenHeight());

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update(deltaTime);
	}

	for (int i = 0; i < collisionObjs.size(); i++)
	{
		if (bulletAABB->Overlaps(collisionObjs[i]) == true)
		{
			std::cout << "hit";
		}
	}
}

void Game::Draw()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Draw();
	}

	EndDrawing();
}

void Game::Shutdown()
{
}
