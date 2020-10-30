#pragma once
#include <string>
#include "vec2.h"
namespace Engine::Utils
{
	/*! @class Input \file input.h
	 *  @brief a wrapper for windows inputs
	 *  @author Kay Hennig
	 *  @date 10.08.2020
	 */
	class Input
	{
	private:
		Input() {}
		enum class KeyState
		{
			NONE,
			PRESSED,
			DOWN,
			RELEASED,
		};
		static KeyState* keyStates;
		/*! @brief the current mouse position on screen */
		static Engine::Math::Vec2 _mousePosition;
	public:
		static const Engine::Math::Vec2& mousePosition;
		/*! @brief Initializes the Inputs */
		static void Init();
		/*! @brief Updates the key states and mouse */
		static void Update();
		/*! @brief Check if key is currently held down
		 *  @param keycode to check for
		 *  @return if the key is held down
		 */
		static bool GetKey(int keycode);
		/*! @brief Check if key is pressed down this frame
		 *  @param keycode to check for
		 *  @return if the key is pressed down
		 */
		static bool GetKeyDown(int keycode);
		/*! @brief Check if key is released this frame
		 *  @param keycode to check for
		 *  @return if the key is released
		 */
		static bool GetKeyUp(int keycode);

	};
}