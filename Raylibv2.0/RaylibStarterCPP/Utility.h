#pragma once
#include "raylib.h"
#include "Vector2.h"

constexpr float min(float a, float b)
{
	return a < b ? a : b;
}

constexpr float max(float a, float b)
{
	return a > b ? a : b;
}

vec2 min(const vec2& a, const vec2& b)
{
	return { min(a.x,b.x), min(a.y,b.y) };
}

vec2 max(const vec2& a, const vec2& b)
{
	return { max(a.x, b.x), max(a.y,b.y) };
}

constexpr float clamp(float t, float a, float b)
{
	return max(a, min(b, t));
}

vec2 clamp(const vec2& t, const vec2& a, const vec2& b)
{
	return max(a, min(b, t));
}
