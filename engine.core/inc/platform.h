#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "singleton.h"

class PlatformHardware
{
	DECLARE_SINGLETON(PlatformHardware)

public:

	struct PlatformInfo
	{
		u8 NumProcessors = 0;
		u64 PhysicalMemory = 0;
		u64 VirtualMemory = 0;
		bool SSEAvailable = false;
		bool SSE2Available = false;
		bool SSE4Available = false;
	};

	static void GetPlatformInfo(PlatformInfo& OutInfo);
	static void OutputInfo();

};
