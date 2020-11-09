#pragma once

#include <vector>
#include "../entity/entity.h"

class IComponentArray
{
public:
	virtual ~IComponentArray() = default;
	virtual void EntityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray
{
public:
	ComponentArray()
	{
		componentArray.resize(1);
	}
	void InsertData(Entity entity, T component)
	{
		if (componentArray.size() < entity)
		{
			componentArray.resize(entity);
		}
		componentArray[entity] = component;
	}
	void RemoveData(Entity entity)
	{

	}

	T& GetData(Entity entity)
	{
		return componentArray[entity];
	}
	void EntityDestroyed(Entity entity)
	{

	}

private:

	std::vector<T> componentArray;
};