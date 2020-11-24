#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUES
#include "basetypes.h"

class RenderWindow;

class Engine
{
public:

	void Initialize(ansistring AppName, u32 ArgCount = 0, const ansistring* ArgList = nullptr);
	void Shutdown(void);

	void Update();

private:


	RenderWindow* renderWindow;
};
