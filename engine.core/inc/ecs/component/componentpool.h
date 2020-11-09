#pragma once

#include "../entity/entity.h"
#include "componentarray.h"
#include <bitset>
#include <unordered_map>


typedef u64 ComponentType;

class ComponentPool
{
public:
	template<typename T>
	void RegisterComponent(std::string identifier)
	{
		componentTypes.insert({ identifier, nextComponentType++ });

		componentArrays.insert({ identifier, new ComponentArray<T> });
	}

	ComponentType GetComponentType(std::string identifier)
	{
		return componentTypes[identifier];
	}

	template<typename T>
	void AddComponent(Entity entity, std::string identifier, T component)
	{
		GetComponentArray<T>(identifier)->InsertData(entity, component);
	}
	template<typename T>
	void RemoveComponent(Entity entity, std::string identifier)
	{
		GetComponentArray<T>(identifier)->RemoveData(entity);
	}

	template<typename T>
	T& GetComponent(Entity entity, std::string identifier)
	{
		return GetComponentArray<T>(identifier)->GetData(entity);
	}

	void EntityDestroyed(Entity entity)
	{
		for (auto const& pair : componentArrays)
		{
			auto const& component = pair.second;
			component->EntityDestroyed(entity);
		}
	}
private:
	ComponentType nextComponentType;

	std::unordered_map<std::string, ComponentType> componentTypes;

	std::unordered_map<std::string, IComponentArray*> componentArrays;

	template<typename T>
	ComponentArray<T>* GetComponentArray(std::string identifier)
	{
		return reinterpret_cast<ComponentArray<T>*>(componentArrays[identifier]);
	}
};