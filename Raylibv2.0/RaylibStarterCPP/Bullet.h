#pragma once

#include "SpriteObject.h"
#include "Turret.h"
#include "AABB.h"
#include "iostream"

class Bullet : public SpriteObject
{
public:
	Bullet();
	bool IsBulletActive = false;

protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

	Texture2D bulletSprite = LoadTexture("res/bulletGreen.png");
	float bulletSpeed;

	AABB* aabbBullet;

};