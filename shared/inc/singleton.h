#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "memory/memutils.h"

#define DECLARE_SINGLETON(CLASSDEF)					\
public:												\
	static CLASSDEF& GetInstance(void)				\
	{												\
		if (!InstancePtr)							\
		{											\
			InstancePtr = new(CLASSDEF);			\
		}											\
		return *InstancePtr;						\
	}												\
	static void DestroyInstance(void)				\
	{												\
		SAFE_DELETE(InstancePtr)					\
	}												\
private:											\
	CLASSDEF(void) = default;						\
	CLASSDEF(CLASSDEF const&) = delete;				\
	CLASSDEF operator=(const CLASSDEF&) = delete;	\
	CLASSDEF(CLASSDEF&& o) = delete;				\
	CLASSDEF& operator=(CLASSDEF&&) = delete;		\
	static CLASSDEF* InstancePtr;

#define DEFINE_SINGLETON(CLASSDEF)					\
	CLASSDEF* CLASSDEF::InstancePtr = nullptr;
