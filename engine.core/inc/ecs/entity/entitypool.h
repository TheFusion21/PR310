#pragma once

#include "../component/componentarray.h"
#include "entity.h"

#include <unordered_map>
#include <queue>
#include <array>



class EntityPool
{
public:
	EntityPool(u64 entityAmount)
	{
		for (u64 i = 0; i < entityAmount; i++)
		{
			availableEntities.push(i);
		}
		lastEntity = entityAmount;
	}
	Entity CreateEntity()
	{
		livingEntities++;
		Entity ent;
		if (availableEntities.empty())
		{
			ent = lastEntity++;
		}
		else
		{
			ent = availableEntities.front();
			availableEntities.pop();
		}
		if (signatures.size() < ent+1)
		{
			signatures.resize(ent+1);
		}
		signatures[ent].reset();
		
		return ent;
	}
	void DestroyEntity(Entity entity)
	{
		livingEntities--;
		availableEntities.push(entity);
	}

	void SetSignature(Entity entity, Signature signature)
	{
		signatures[entity] = signature;
	}

	Signature GetSignature(Entity entity)
	{
		return signatures[entity];
	}

private:
	u64 livingEntities;

	u64 lastEntity;
	std::queue<Entity> availableEntities;

	std::vector<Signature> signatures;

};