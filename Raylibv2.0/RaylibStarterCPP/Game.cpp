#include "Game.h"

void Game::Init()
{
	player = new TankPlayer;
	turret = new Turret;

	turret->SetParent(player);

	gameObjects.push_back(player);
}

void Game::Update(float deltaTime)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		bullet = new Bullet;
		gameObjects.push_back(bullet);
		bullet->SetLocalPosition(turret->GetWorldPosition());
 		bullet->SetLocalRotation(turret->GetWorldRotation());
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
