#pragma once

// EXTERNAL INCLUDES
#include <vector>
// INTERNAL INCLUDES
#include "basetypes.h"
#include "singleton.h"

struct ProfilerRecord
{
	ansistring ScopeName = nullptr;
	ansistring FileName = nullptr;
	u32 Line = 0;

	u64 Frequency = 0;
	u64 EndTime = 0;
	u64 StartTime = 0;
};

class PerformanceProfiler
{
	DECLARE_SINGLETON(PerformanceProfiler);

public:

	~PerformanceProfiler();
	bool AddRecord(const struct ScopedRecord& Record);

private:

	std::vector<ProfilerRecord> Records;

};
