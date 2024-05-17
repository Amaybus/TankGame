#pragma once
#include "SpriteObject.h"
#include "AABB.h"

class TankPlayer : public SpriteObject
{
protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

	Texture2D tankSprite = LoadTexture("res/greenTank.png");

public:
	TankPlayer();
};