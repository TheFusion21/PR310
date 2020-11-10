#pragma once

// EXTERNAL INCLUDES
// INTENRAL INCLUDES
#include "ecs/component/componentcontext.h"
#include "ecs/entity/entitycontext.h"
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
	SystemPool systemPool;

};
