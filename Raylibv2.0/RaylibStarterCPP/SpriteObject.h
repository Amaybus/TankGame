#pragma once

#include "Raylib.h"
#include "GameObject.h"

class SpriteObject : public GameObject
{
public:
	Texture2D* Sprite;
	vec3 Origin;
	Color Tint;

	SpriteObject();

protected:
	void OnDraw() override;
};

