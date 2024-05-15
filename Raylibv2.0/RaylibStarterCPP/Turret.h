#pragma once

#include "SpriteObject.h"
#include "TankPlayer.h"

class Turret : public SpriteObject
{
protected:
	Texture2D turretSprite = LoadTexture("res/greenTurret.png");

public:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;
	Turret();
};