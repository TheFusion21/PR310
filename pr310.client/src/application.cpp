// EXTERNAL INCLUDES

// INTENRAL INCLUDES
#include "appinfo.h"
#include "application.h"
#include "profiling/profiler.h"
#include "profiling/record.h"

void Application::Initialize(u32 ArgCount, const ansistring* ArgList)
{
	FUNCTION_PROFILING()
	
	this->GameEngine.Initialize(APPLICATION_NAME, ArgCount, ArgList);
}
void Application::Execute()
{
	FUNCTION_PROFILING();
	// TODO: Do something .. xD
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
