#pragma once

// EXTERNAL INCLUDES
#if defined (_WIN32)
#	include <Windows.h>
#endif
// INTERNAL INCLUDES
#include "profiling/profiler.h"
#include "profiling/record.h"

ScopedRecord::ScopedRecord(ansistring ScopeName, ansistring FileName, u32 Line) :
	ScopeName(ScopeName),
	FileName(FileName),
	Line(Line)
{
	// Prepare profiling.

	LARGE_INTEGER Start = { };
	LARGE_INTEGER Frequency = { };

#if defined (_WIN32)
	if (QueryPerformanceFrequency(&Frequency)
		&& QueryPerformanceCounter(&Start))
	{
		this->Frequency = Frequency.QuadPart;
		this->StartTime = Start.QuadPart;
	}
#endif
}

ScopedRecord::~ScopedRecord(void)
{
#if defined (_WIN32)
	LARGE_INTEGER End = { };
	if (QueryPerformanceCounter(&End))
	{
		this->EndTime = End.QuadPart;
	}
#endif

	// TODO: Add to the application profiler
	// We could also have a dedicated frame profiler
	PerformanceProfiler::GetInstance().AddRecord(*this);
}
