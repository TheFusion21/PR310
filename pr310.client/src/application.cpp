// EXTERNAL INCLUDES

// INTENRAL INCLUDES
#include "appinfo.h"
#include "application.h"
#include "profiling/profiler.h"
#include "profiling/record.h"

#include "ecs/component/componentpool.h"
#include "ecs/entity/entitypool.h"
#include "ecs/system/systempool.h"
#include "ecs/component/transform.h"
#include "ecs/system/testsystem.h"
void Application::Initialize(u32 ArgCount, const ansistring* ArgList)
{
	FUNCTION_PROFILING()
	
	this->GameEngine.Initialize(APPLICATION_NAME, ArgCount, ArgList);
}

ComponentPool componentPool;
EntityPool entityPool(1024);
SystemPool systemPool;
Entity testEntity;
TestSystem* testSystem = nullptr;
void Application::Execute()
{
	FUNCTION_PROFILING();


	testSystem = systemPool.RegisterSystem<TestSystem>(NameToText(TestSystem));


	componentPool.RegisterComponent<Transform>(NameToText(Transform));

	Signature sysSig;
	sysSig.set(componentPool.GetComponentType(NameToText(Transform)));
	systemPool.SetSignature(NameToText(TestSystem), sysSig);

	

	testEntity = entityPool.CreateEntity();
	componentPool.AddComponent(testEntity, NameToText(Transform), Transform());

	Signature testSig = entityPool.GetSignature(testEntity);
	testSig.set(componentPool.GetComponentType(NameToText(Transform)));
	entityPool.SetSignature(testEntity, testSig);

	systemPool.EntitySignatureChanged(testEntity, entityPool.GetSignature(testEntity));

	while (true)
	{
		testSystem->Update(componentPool);
	}
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
