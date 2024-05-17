#pragma once

#include "SpriteObject.h"
#include "Turret.h"
#include "AABB.h"
#include "iostream"

class Bullet : public SpriteObject
{
public:
	Bullet();
	AABB* aabbBullet;

protected:
	void OnUpdate(float deltaTime) override;
	void OnDraw() override;

	Texture2D bulletSprite = LoadTexture("res/bulletGreen.png");
	float bulletSpeed;


};

//	100, 0
//  0, 0
//  0, 100
//  100, 100