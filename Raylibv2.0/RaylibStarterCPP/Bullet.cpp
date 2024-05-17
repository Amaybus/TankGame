#include "Bullet.h"

Bullet::Bullet()
{
	Sprite = &bulletSprite;
	bulletSpeed = 300.0f;
	aabbBullet = new AABB(vec2(GetWorldPosition().x, GetWorldPosition().y), vec2(Sprite->width, Sprite->height));
}

void Bullet::OnUpdate(float deltaTime)
{
	vec3 movement = GetForward() * (bulletSpeed * deltaTime);
	Translate(movement);
}

void Bullet::OnDraw()
{
	 Origin = vec3(-2, 0.5, 0);
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


