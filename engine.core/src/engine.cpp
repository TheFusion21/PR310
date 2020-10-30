// EXTERNAL INCLUDES

// INTERNAL INCLUES
#include "engine.h"
#include "platform.h"
#include "profiling/record.h"

void Engine::Initialize(ansistring AppName, u32 ArgCount, const ansistring* ArgList)
{
	FUNCTION_PROFILING();
	
	// TODO: Submodule scope
	{
		SCOPED_PROFILING("Init Submodules");

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
	FUNCTION_PROFILING();

	// TODO: Submodule scope
	{
		SCOPED_PROFILING("Shutdown Submodules");
		// Notify submodules for shutdown!
		// Renderer
		// Audio
		// Other Subsystems
	}
}

