#pragma once

#include "system.h"
#include "../component/componentpool.h"
#include "../component/transform.h"

#define NameToText(x) #x
class TestSystem : public System
{
public:
	void Update(ComponentPool& coord)
	{
		for (auto const& entity : entities)
		{
			auto& transform = coord.GetComponent<Transform>(entity, NameToText(Transform));

			transform.position += Vec3::UnitZ;
		}
	}
};