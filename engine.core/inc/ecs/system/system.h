#pragma once

#include "../entity/entity.h"
#include <set>

class ComponentContext;
class System
{
public:
	virtual void Update(ComponentContext& coord) = 0;

	std::set<Entity> entities;
};