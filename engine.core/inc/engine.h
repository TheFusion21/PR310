#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUES
#include "basetypes.h"

class Engine
{
public:

	void Initialize(ansistring AppName, u32 ArgCount = 0, const ansistring* ArgList = nullptr);
	void Shutdown(void);

};
