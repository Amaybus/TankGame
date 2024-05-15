#include "TankPlayer.h"
#include <iostream>

TankPlayer::TankPlayer()
{
	Sprite = &tankSprite;
	SetLocalPosition(400, 225);
}

void TankPlayer::OnUpdate(float deltaTime)
{
	const float moveSpeed = 100.0f;
	const float rotSpeed = 5.0f;
	float yMove = 0.0f;
	float rot = 0.0f;

	if (IsKeyDown(KEY_W))
	{
		yMove += moveSpeed;
	}
	if (IsKeyDown(KEY_S))
	{
		yMove -= moveSpeed;
	}
	if (IsKeyDown(KEY_A))
	{
		rot -= rotSpeed;
	}
	if (IsKeyDown(KEY_D))
	{
		rot += rotSpeed;
	}
	vec3 finalMove = GetForward() * (yMove * deltaTime);
	float finalRot = (rot * deltaTime);
	Translate(finalMove);
	Rotate(finalRot);
}

void TankPlayer::OnDraw()
{
	Origin = vec3(0.5, 0.5, 0.5);
	Tint = Color({ 255,255,255,255 });

	vec3 pos = GetWorldPosition();
	float rotation = GetWorldRotation() * RAD2DEG;
	vec3 scale = GetWorldScale();

	DrawTexturePro(*Sprite, { 0,0, (float)Sprite->width, (float)Sprite->height },
		{ pos.x, pos.y, (float)Sprite->width * scale.x, (float)Sprite->height * scale.y },
		{ (float)Sprite->width * Origin.x * scale.x, (float)Sprite->height * Origin.y * scale.y },
		rotation,
		Color(Tint));
}
