// EXTERNAL INCLUDES
#include <Windows.h>
// INTERNAL INCLUES
#include "engine.h"
#include "platform.h"
#include "profiling/record.h"

void Engine::Initialize(ansistring AppName, u32 ArgCount, const ansistring* ArgList)
{
	AE_FUNCTION_PROFILING();

	// TODO: Configuration Scope
	{
		AE_SCOPED_PROFILING("Init Config");

		// Load Engine Config
		// Parse Command Line - Override Engine Config
		size Count = 1;
		ansistring Commandline[] = {
			"Engine.WindowNoBorder=true",
			"Renderer.ResX=800",
			"Renderer.ResY=600"
		};
	}
	
	// TODO: Submodule scope
	{
		AE_SCOPED_PROFILING("Init Submodules");

		// Create and init all submodules
		// Renderer
		// Audio
		// Other Subsystems
	}

	// TODO: Log Hardware
	PlatformHardware::OutputInfo();
}
void Engine::Shutdown()
{
	AE_FUNCTION_PROFILING();

	// TODO: Submodule scope
	{
		AE_SCOPED_PROFILING("Shutdown Submodules");
		// Notify submodules for shutdown!
		// Renderer
		// Audio
		// Other Subsystems
	}
}

