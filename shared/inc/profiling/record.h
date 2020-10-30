#pragma once

// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "basetypes.h"

struct ScopedRecord
{
public:

	ScopedRecord(ansistring ScopeName, ansistring FileName, u32 Line);
	~ScopedRecord(void);

	const ansistring ScopeName	= nullptr;
	const ansistring FileName	= nullptr;
	const u32 Line				= 0;

	u64 Frequency				= 0;
	u64 EndTime					= 0;
	u64 StartTime				= 0;

};

#ifdef ENGINE_COMPILE_DEBUG
#	define FUNCTION_PROFILING()			ScopedRecord RecordL##__Line__(__FUNCSIG__, __FILE__, __LINE__);
#	define SCOPED_PROFILING(ScopeName)	ScopedRecord RecordL##__Line__(ScopeName, __FILE__, __LINE__);
#else
#	define FUNCTION_PROFILING();
#	define SCOPED_PROFILING(ScopeName);
#endif
