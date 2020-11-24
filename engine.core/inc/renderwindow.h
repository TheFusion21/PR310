#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"


/*!
	* @brief	This class defines a render window.
	*/
class RenderWindow
{
public:

	/*!
	* @brief	Default constructor of RenderWindow.
	*/
	RenderWindow() { }
	/*!
	* @brief	Default destructor of RenderWindow.
	*/
	~RenderWindow() { }

	/*!
	* @brief	This method initializes a new RenderWindow.
	* @param	title is the title of the window after its creation.
	* @param	width is the width of the window after its creation.
	* @param	height is the height of the window after its creation.
	* @return	the handle of the current window as a pointer to int.
	*/
	intptr_t Initialize(const char* title, u32 width, u32 height);
	/*!
	* @brief	This method dispatches the window messages.
	*/
	void PumpMessages(void);

private:

	intptr_t handle = 0;

};
	
