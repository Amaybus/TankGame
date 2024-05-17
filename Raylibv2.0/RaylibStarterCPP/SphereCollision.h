#pragma once

#include "Vector2.h"

struct SphereCol
{
	SphereCol();
	SphereCol(vec2 p, float r);

	vec2 centre;
	float radius;

};
