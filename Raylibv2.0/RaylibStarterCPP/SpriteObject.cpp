#include "SpriteObject.h"

#include "utils.h"
#include <iostream>

SpriteObject::SpriteObject()
{
	Sprite = nullptr;
	Origin = vec3(0.5, 0.5, 0.5);
	Tint = Color({255,255,255,255});
}

void SpriteObject::OnDraw()
{
	vec3 pos = GetWorldPosition();
	float rotation = GetWorldRotation() * RAD2DEG;
	vec3 scale = GetWorldScale();

	DrawTexturePro(*Sprite, { 0,0, (float)Sprite->width, (float)Sprite->height },
		{ pos.x, pos.y, (float)Sprite->width * scale.x, (float)Sprite->height * scale.y },
		{ (float)Sprite->width * Origin.x * scale.x, (float)Sprite->height * Origin.y * scale.y },
		rotation,
		Color(Tint));
	DrawCircleV({ pos.x, pos.y }, 10, RED);
}
