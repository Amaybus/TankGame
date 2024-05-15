#pragma once
#include "raylib.h"

constexpr float min(float a, float b)
{
	return a < b ? a : b;
}

constexpr float max(float a, float b)
{
	return a > b ? a : b;
}

Vector2 min(const Vector2& a, const Vector2& b)
{
	return { min(a.x,b.x), min(a.y,b.y) };
}

Vector2 max(const Vector2& a, const Vector2& b)
{
	return { max(a.x, b.x), max(a.y,b.y) };
}

constexpr float clamp(float t, float a, float b)
{
	return max(a, min(b, t));
}
