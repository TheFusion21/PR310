#pragma once

#include "../entity/entity.h"
#include "../entity/entitycontext.h"
#include "system.h"
#include <string>
#include <unordered_map>
#include <bitset>
#include "profiling/record.h"

typedef void(*InitializeCallback)(void);
typedef void(*ExecuteCallback)(std::vector<Entity>&, float);
typedef void(*TearDownCallback)(void);

class SystemPool
{
public:

	template<typename T>
	void RegisterExecuteSystem(Signature Sign)
	{
		this->InitializeSystems.insert({ Sign, &T::Initialize });
		this->ExecuteSystems.insert({ Sign, &T::Execute });
		this->TearDownSystems.insert({ Sign, &T::TearDown });
	}
	template<typename T>
	void RegisterInitializeSystem(Signature Sign)
	{
		InitializeSystems.insert({ Sign, &T::Initialize });
		TearDownSystems.insert({ Sign, &T::TearDown });
	}

	void Initialize(void)
	{
		FUNCTION_PROFILING();
		for (const auto& Pair : this->InitializeSystems)
		{
			auto* InitializeSystem = reinterpret_cast<InitializeCallback>(Pair.second);
			if (!InitializeSystem) continue;

			InitializeSystem();
		}
	}
	void Execute(void)
	{
		FUNCTION_PROFILING();
		auto& Context = EntityContext::GetInstance();
		for (const auto& Pair : this->ExecuteSystems)
		{
			auto* ExecuteSystem = reinterpret_cast<ExecuteCallback>(Pair.second);
			if (!ExecuteSystem) continue;

			Signature SystemSignature = Pair.first;

			std::vector<Entity> FilteredEntities = Context.FilteredEntities(SystemSignature);

			ExecuteSystem(FilteredEntities, 0.0f); // TODO: Get DeltaTime
		}
	}
	void TearDown(void)
	{
		FUNCTION_PROFILING();
		for (const auto& Pair : this->TearDownSystems)
		{
			auto* TearDownSystem = reinterpret_cast<TearDownCallback>(Pair.second);
			if (!TearDownSystem) continue;

			TearDownSystem();
		}
	}

private:

	std::unordered_map<Signature, InitializeCallback> InitializeSystems;
	std::unordered_map<Signature, ExecuteCallback> ExecuteSystems;
	std::unordered_map<Signature, TearDownCallback> TearDownSystems;

};