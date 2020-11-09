#pragma once

#include "../entity/entity.h"
#include <set>
class ComponentPool;
class System
{
public:
	virtual void Update(ComponentPool& coord) = 0;

	std::set<Entity> entities;
};