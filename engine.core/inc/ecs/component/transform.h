#pragma once

#include "basetypes.h"
#include "math/vec3.h"
#include "math/quaternion.h"


struct Transform
{
	Vec3 position;
	Quaternion rotation;
	Vec3 scale;

};