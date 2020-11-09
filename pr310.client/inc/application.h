#pragma once

// EXTERNAL INCLUDES
// INTENRAL INCLUDES
#include "ecs/component/componentpool.h"
#include "ecs/entity/entitypool.h"
#include "ecs/system/systempool.h"
#include "engine.h"

class Application
{
public:

	void Initialize(u32 ArgCount = 0, const ansistring* ArgList = nullptr);
	void Execute();
	void Shutdown();

private:

	Engine GameEngine;

	ComponentPool componentPool;
	EntityPool entityPool = EntityPool(1024);
	SystemPool systemPool;

};
