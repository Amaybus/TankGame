#pragma once

#include "SpriteObject.h"
#include "Turret.h"
#include "CirlceCollision.h"
#include "iostream"

class Bullet : public SpriteObject
{
public:
	Bullet();
	CirlceCol* bulletCol;

protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

	Texture2D bulletSprite = LoadTexture("res/bulletGreen.png");
	float bulletSpeed;

};
