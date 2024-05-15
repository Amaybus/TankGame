#pragma once

#include "Utility.h"
#include "Vector2.h"

#include <vector>

struct AABB
{
	vec2 min;
	vec2 max;

	AABB();
	AABB(vec2 min,  vec2 max);

	vec2 Centre();
	vec2 Extents() const;

	std::vector<vec2> Corners() const;
	void Fit(const vec2* points, unsigned int count);
	
	bool Overlaps(const vec2& p) const;
	bool Overlaps(const AABB& other) const;
	vec2 ClosestPoint(const vec2& p) const;
};
