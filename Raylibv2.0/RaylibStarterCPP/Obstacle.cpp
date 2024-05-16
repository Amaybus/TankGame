#include "Obstacle.h"

Obstacle::Obstacle()
{
	SetLocalPosition(100, 100);
}


void Obstacle::OnDraw()
{
	DrawRectangle(LocalPosition.x, LocalPosition.y, 100, 100, BLUE);
}

void Obstacle::OnUpdate(float deltaTime)
{
	
}
