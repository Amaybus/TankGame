#include "AABB.h"

AABB::AABB()
	: min{0,0}, max{0,0}
{
}

AABB::AABB(vec2 min,  vec2 max)
	: min(min), max(max)
{
}

vec2 AABB::Centre() 
{
	return (min + max) * 0.5f;
}

vec2 AABB::Extents() const
{
	return {abs(max.x - min.x) * 0.5f,
			abs(max.y - min.y) * 0.5f };
}

std::vector<vec2> AABB::Corners() const
{
	std::vector<vec2> corners(4);
	corners[0] = min;
	corners[1] = { min.x,min.y };
	corners[2] = max;
	corners[3] = { max.x,max.y };
	return corners;
}

void AABB::Fit(const vec2* points, unsigned int count)
{
	min = { FLT_MAX, FLT_MAX };
	max = { FLT_MIN, FLT_MIN };

	for (unsigned int i = 0; i < count; i++)
	{
		
		min = min.Min(min, *points);
		max = max.Max(max, *points);
	}
}

bool AABB::Overlaps(const vec2& p) const
{
	return !(p.x < min.x || p.y < min.y || p.x > max.x || p.y > max.y);
}

bool AABB::Overlaps(const AABB& other) const
{
	return !(max.x < other.min.x || max.y < other.min.y 
		  || min.x>other.max.x || min.y > other.max.y);
}

vec2 AABB::ClosestPoint(vec2& p) 
{
	return p.Clamp(p, min, max);
}

void AABB::SetToTransformedBox(const MathClasses::Matrix3& m)
{
	if (m.m1 > 0.0f)
	{
		min.x += m.m1 * min.x;
		max.x += m.m1 * max.x;
	}
	else
	{
		min.x += m.m1 * max.x;
		max.x += m.m1 * min.x;
	}
	//-----------------------------

	if (m.m4 > 0.0f)
	{
		min.x += m.m4 * min.x;
		max.x += m.m4 * max.x;
	}
	else
	{
		min.x += m.m4 * max.x;
		max.x += m.m4 * min.x;
	}
	//-----------------------------

	if (m.m7 > 0.0f)
	{
		min.x += m.m7 * min.x;
		max.x += m.m7 * max.x;
	}
	else
	{
		min.x += m.m7 * max.x;
		max.x += m.m7 * min.x;
	}
	//-----------------------------

	if (m.m2 > 0.0f)
	{
		min.x += m.m2 * min.x;
		max.x += m.m2 * max.x;
	}
	else
	{
		min.x += m.m2 * max.x;
		max.x += m.m2 * min.x;
	}
	//-----------------------------

	if (m.m5 > 0.0f)
	{
		min.x += m.m5 * min.x;
		max.x += m.m5 * max.x;
	}
	else
	{
		min.x += m.m5 * max.x;
		max.x += m.m5 * min.x;
	}
	//-----------------------------

	if (m.m8 > 0.0f)
	{
		min.x += m.m8 * min.x;
		max.x += m.m8 * max.x;
	}
	else
	{
		min.x += m.m8 * max.x;
		max.x += m.m8 * min.x;
	}
	//-----------------------------

	if (m.m3 > 0.0f)
	{
		min.x += m.m3 * min.x;
		max.x += m.m3 * max.x;
	}
	else
	{
		min.x += m.m3 * max.x;
		max.x += m.m3 * min.x;
	}
	//-----------------------------

	if (m.m6 > 0.0f)
	{
		min.x += m.m6 * min.x;
		max.x += m.m6 * max.x;
	}
	else
	{
		min.x += m.m6 * max.x;
		max.x += m.m6 * min.x;
	}
	//-----------------------------

	if (m.m9 > 0.0f)
	{
		min.x += m.m9 * min.x;
		max.x += m.m9 * max.x;
	}
	else
	{
		min.x += m.m9 * max.x;
		max.x += m.m9 * min.x;
	}
}
