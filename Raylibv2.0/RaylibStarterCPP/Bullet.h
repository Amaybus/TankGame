#pragma once

#include "SpriteObject.h"
#include "Turret.h"
#include "AABB.h"

class Bullet : public SpriteObject
{
public:
	Bullet();

protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

	Texture2D bulletSprite = LoadTexture("res/bulletGreen.png");
	float bulletSpeed;

	AABB* aabbBullet;
};