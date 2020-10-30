#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "appwindow.h"
#include "gameobject.h"
#include "mesh.h"

namespace Game::Client
{
	/*! @class Application \file client.h
	 *  @brief The main class used in for starting the game/client/engine
	 *  @note \link Application::Init \endlink is required to call \link Application::Run \endlink
	 *  @author Kay Hennig
	 *  @date 03.08.2020
	 */
	class Application
	{
	private:
		Engine::Core::AppWindow window;
		enum class AppState
		{
			Started,
			Running,
			Stopped
		} appState = AppState::Started;

		std::vector<GameObject*> gameObjects;

	public:
		/*! @brief Initializes the Engines renderer and the client window */
		void Init();
		/*! @brief Starts the game loop */
		void Run();
		/*! @brief Cleanup and a prober exit of renderer will be done */
		void Shutdown();
	};
}
