#include "Bullet.h"

Bullet::Bullet()
{
	Sprite = &bulletSprite;
	bulletSpeed = 300.0f;
	//aabbBullet = new AABB(vec2(bulletSprite.height, 0), vec2(0, bulletSprite.width));
	IsBulletActive = true;
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

	 //AABB* boundingBox = dynamic_cast<AABB*>(GetChild(0));
	// std::vector<vec2> corners= aabbBullet->Corners();
	// DrawCircle(corners[0].x, corners[0].y, 5, RED);
	// DrawCircle(corners[1].x, corners[1].y, 5, RED);
	// DrawCircle(corners[2].x, corners[2].y, 5, RED);
	// DrawCircle(corners[3].x, corners[3].y, 5, RED);

}

