#pragma once

// EXTERNAL INCLUDES
#include <Windows.h>
// INTERNAL INCLUDES
#include "types.h"


namespace Engine::Core
{
	/*! @class AppWindow \file AppWindow.h
	 *  @brief This class is used to manage the window shown to the user
	 *  @note \link AppWindow::Init \endlink needs to run before using the window
	 *  @author Kay Hennig
	 *  @date 03.08.2020
	 */
	class AppWindow
	{
	private:
		HWND hwnd = NULL;
	public:
		bool isInit = false;
		/*! @brief This will initialize a window
		 *  @param name is the name the window should have
		 *  @param width is the horizontal size of the window
		 *  @param height is the vertical size of the window
		 * 	@return Nothing
		 */
		void Init(AnsiString name, int width, int height);
		/*! @brief Displays the window to the user */
		void Show();
		/*! @brief Hides the window to the user */
		void Hide();
		/*! @brief Maximizes the window */
		void Maximize();
		/*! @brief Minimizes the window */
		void Minimize();
		/*! @brief Resizes the buffers to the window size
		 *  @return if resize was successful
		*/
		bool Resize();
		/*! @brief Retrieves the messages from the window and translates / dispatches them
		 *  @return is closed message retrieved
		*/
		bool MessagePump();
		/*! @brief gets the size of the window
		 *  @param width is the horizontal size to get
		 *  @param height is the vertical size to get
		 *  @return if getting size was successful
		*/
		bool GetClientSize(ui32& width, ui32& height);
		/*! @brief retrieve the handle of the window
		 *  @return generic variable of the handle
		*/
		ui64 GetHandle();
	};
}
