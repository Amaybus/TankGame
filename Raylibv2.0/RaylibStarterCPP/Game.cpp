#include "Game.h"

void Game::Init()
{
	player = new TankPlayer;
	turret = new Turret;
	obstacle = new Obstacle;

	turret->SetParent(player);

	gameObjects.push_back(player);
	gameObjects.push_back(obstacle);

	gameObjects.push_back(obstacle->aabbObstacle); // delete after debugging

	collisionObjs.push_back(*obstacle->aabbObstacle);
}

void Game::Update(float deltaTime, float screenWidth, float screenHeight)
 {

	if (toDelete.size() > 0)
	{
		for (int i = 0; i < toDelete.size(); i++)
		{
			delete toDelete[i];
		}
		toDelete.clear();
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		bullet = new Bullet;

		gameObjects.push_back(bullet);

		gameObjects.push_back(bullet->bulletCol);
		bullet->SetLocalPosition(turret->GetWorldPosition());
 		bullet->SetLocalRotation(turret->GetWorldRotation());
	}
	
	if (bullet != nullptr)
	{
		vec3 pos = bullet->GetWorldPosition();
		if (pos.x < 0 || pos.x > screenWidth || pos.y < 0 || pos.y > screenHeight)
		{
			toDelete.push_back(bullet);
			toDelete.push_back(bullet->bulletCol);
			gameObjects.erase(std::find(gameObjects.begin(), gameObjects.end(), bullet));
			gameObjects.erase(std::find(gameObjects.begin(), gameObjects.end(), bullet->bulletCol));
			bullet = nullptr;
		}
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update(deltaTime);
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
