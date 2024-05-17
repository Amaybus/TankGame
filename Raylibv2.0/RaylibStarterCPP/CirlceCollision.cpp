#include "CirlceCollision.h"

CirlceCol::CirlceCol()
	: centre(vec2(0, 0)), radius(0)
{
}

CirlceCol::CirlceCol(vec2 p, float r)
	: centre{ p }, radius{ r }
{
}

void CirlceCol::Fit(vec2* points, unsigned int count)
{
	vec2 min = { FLT_MAX, FLT_MAX };
	vec2 max = { FLT_MIN, FLT_MIN };

	for (unsigned int i = 0; 0 < count; i++)
	{
		min = min.Min(min, *points);
		max = max.Max(max, *points);
	}

	centre = (min + max) * 0.5f;
	radius = centre.DistanceTo(max);
}

void CirlceCol::Fit(std::vector<vec2>& points)
{
	vec2 min = { FLT_MAX, FLT_MAX };
	vec2 max = { FLT_MIN, FLT_MIN };

	for (auto& p : points)
	{
		min = min.Min(min, p);
		max = max.Max(max, p);
	}
	
	centre = (min + max) * 0.5f;
	radius = centre.DistanceTo(max);
}

bool CirlceCol::Overlaps(vec2 p)
{
	vec2 toPoint = p - centre;
	return toPoint.MagnitudeSqr() <= (radius * radius);
}

bool CirlceCol::Overlaps(AABB aabb)
{
	auto diff = aabb.ClosestPoint(centre) - centre;
	return diff.Dot(diff) <= (radius * radius);
}

vec2 CirlceCol::ClosestPoint(vec2 p)
{
	vec2 toPoint = p - centre;

	if (toPoint.MagnitudeSqr() > radius)
	{
		toPoint = toPoint.Normalised() * radius;
	}
	return centre + toPoint;
}
