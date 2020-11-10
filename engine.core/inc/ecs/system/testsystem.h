#pragma once

#include "system.h"
#include "../component/componentcontext.h"
#include "../component/transform.h"

#define NameToText(x) #x

class TestSystem
{
public:

	static void Initialize(void)
	{

	}
	static void Execute(std::vector<Entity>& entities, float deltaTime)
	{
		for (auto const& entity : entities)
		{
			auto& CompCont = ComponentContext::GetInstance();
			auto* transform = CompCont.GetComponent<Transform>(entity);
			if (!transform) return;

			transform->position += Vec3::UnitZ;
		}
	}
	static void TearDown(void)
	{

	}

};
