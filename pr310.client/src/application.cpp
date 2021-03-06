// EXTERNAL INCLUDES

// INTENRAL INCLUDES
#include "appinfo.h"
#include "application.h"
#include "scenenode.h"
#include "profiling/profiler.h"
#include "profiling/record.h"

#include "ecs/component/transform.h"
#include "ecs/system/testsystem.h"
void Application::Initialize(u32 ArgCount, const ansistring* ArgList)
{
	FUNCTION_PROFILING()
	
	this->GameEngine.Initialize(APPLICATION_NAME, ArgCount, ArgList);
}

void Application::Execute()
{
	FUNCTION_PROFILING();
	
	//auto& CompCont = ComponentContext::GetInstance();
	//CompCont.RegisterComponent<Transform>();

	//Signature sysSig;
	//sysSig.set(Transform::ID, true);
	//systemPool.RegisterExecuteSystem<TestSystem>(sysSig);
	//
	//auto& EntCont = EntityContext::GetInstance();
	//auto Ent = EntCont.CreateEntity();

	//CompCont.AddComponent<Transform>(Ent);

	//systemPool.Initialize();
	//for (int i = 0; i < 100000; i++)
	//{
	//	SCOPED_PROFILING("Loop");
	//	systemPool.Execute();
	//}
	//systemPool.TearDown();

	auto root = SceneNode("root");
	auto rootTransform = Transform();
	root.SetTransform(rootTransform);
	
	auto child = SceneNode("child");
	auto childTransform = Transform();
	childTransform.position = Vec3(5, -3, 0);
	child.SetTransform(childTransform);

	rootTransform.position = Vec3(-1, -1, -1);
	root.SetTransform(rootTransform);
	
	root.AddChild(&child);
	root.Update();

	child.GetParent()->RemoveChild(&child);
	child.AddChild(&root);

	root.Update();

	while (true)
	{
		GameEngine.Update();
	}

	return;
}

void Application::Shutdown()
{
	{
		FUNCTION_PROFILING();

		this->GameEngine.Shutdown();
	}

	// NOTE: Past this point there shall be no profiling!
	PerformanceProfiler::DestroyInstance();
}
