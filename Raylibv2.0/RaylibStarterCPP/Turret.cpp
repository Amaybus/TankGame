#include "Turret.h"
#include <iostream>

Turret::Turret()
{
	Sprite = &turretSprite;
}

void Turret::OnDraw()
{
	Origin = vec3(0, 0.5, 0);
	vec3 pos = GetWorldPosition();
	float rotation = GetWorldRotation() * RAD2DEG;
	vec3 scale = GetWorldScale();

	DrawTexturePro(*Sprite, { 0,0, (float)Sprite->width, (float)Sprite->height },
		{ pos.x, pos.y, (float)Sprite->width * scale.x, (float)Sprite->height * scale.y },
		{ (float)Sprite->width * Origin.x * scale.x, (float)Sprite->height * Origin.y * scale.y },
		rotation,
		Color(Tint));
}

void Turret::OnUpdate(float deltaTime)
{
	float rotSpeed = 5.0f;
	float rot = 0;

	if (IsKeyDown(KEY_Q))
	{
		rot -= (rotSpeed * deltaTime);
	}
	if (IsKeyDown(KEY_E))
	{
		rot += (rotSpeed * deltaTime);
	}
	float finalRot = rot;
	Rotate(finalRot);
}
