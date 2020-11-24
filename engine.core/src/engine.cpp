// EXTERNAL INCLUDES

// INTERNAL INCLUES
#include "engine.h"
#include "platform.h"
#include "profiling/record.h"
#include "renderwindow.h"
#include "input/mouse.h"

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

	renderWindow = new RenderWindow();
	renderWindow->Initialize(AppName, 1366, 768);
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

void Engine::Update()
{
	renderWindow->PumpMessages();

	MouseInput::GetInstance().Update();
}

