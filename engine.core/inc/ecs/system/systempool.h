#pragma once

#include "../entity/entity.h"
#include "system.h"
#include <string>
#include <unordered_map>
#include <bitset>



class SystemPool
{
public:
	~SystemPool()
	{
		for (auto const& pair : systems)
		{
			if(pair.second)
				delete pair.second;
		}
	}
	template<typename T>
	T* RegisterSystem(std::string identifier)
	{
		T* system = new T();
		systems.insert({ identifier, system });
		return system;
	}
	void SetSignature(std::string identifier, Signature signature)
	{
		signatures.insert({ identifier, signature });
	}

	void EntityDestroyed(Entity entity)
	{
		for (auto const& pair : systems)
		{
			auto const& system = pair.second;

			system->entities.erase(entity);
		}
	}
	void EntitySignatureChanged(Entity entity, Signature entitySignature)
	{
		for (auto const& pair : systems)
		{
			auto const& type = pair.first;
			auto const& system = pair.second;
			auto const& systemSig = signatures[type];

			if ((entitySignature & systemSig) == systemSig)
			{
				system->entities.insert(entity);
			}
			else
			{
				system->entities.erase(entity);
			}
		}
	}
private:
	std::unordered_map<std::string, Signature> signatures;

	std::unordered_map<std::string, System*> systems;
};