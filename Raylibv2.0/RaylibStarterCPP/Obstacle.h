#pragma once
#include "SpriteObject.h"
#include "AABB.h"
#include "raylib.h"

class Obstacle : public SpriteObject
{
public:
	Obstacle();

protected:
	void OnDraw() override;
	void OnUpdate(float deltaTime) override;

};