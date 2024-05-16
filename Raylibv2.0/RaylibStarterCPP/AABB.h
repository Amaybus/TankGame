#pragma once

#include "Vector2.h"
#include "Matrix3.h"
#include "GameObject.h"
#include <string>

#include <vector>

struct AABB : public GameObject
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
	vec2 ClosestPoint(vec2& p);

	void SetToTransformedBox(const MathClasses::Matrix3& m);

	bool operator==(const AABB& rhs);
	bool operator!=(const AABB& rhs);
};