#pragma once

#include "Vector2.h"
#include "AABB.h"
#include "GameObject.h"
#include <vector>

struct CirlceCol : public GameObject
{
	CirlceCol();
	CirlceCol(vec2 p, float r);

	void Fit(vec2* points, unsigned int count);
	void Fit(std::vector<vec2>& points);

	bool Overlaps(vec2 p);
	bool Overlaps(AABB aabb);

	vec2 ClosestPoint(vec2 p);

	vec2 centre;
	float radius;

	void OnDraw() override;
	void OnUpdate(float deltaTime) override;
};