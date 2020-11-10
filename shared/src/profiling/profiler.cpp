
// EXTERNAL INCLUDES
#include <cstdio>
#include <cmath>
// INTERNAL INCLUDES
#include "logging.h"
#include "profiling/profiler.h"
#include "profiling/record.h"

DEFINE_SINGLETON(PerformanceProfiler)

PerformanceProfiler::~PerformanceProfiler()
{
	FILE* File = nullptr;
	File = fopen("./profiler.json", "w+");
	
	if (!File) return;

	fwrite("[\n", 2, 1, File);
	for (int i = 0; i< this->Records.size(); i++)
	{
		auto& Record = this->Records[i];

		if (i > 0) fwrite(",\n", 2, 1, File);

		fwrite("\t{", 2, 1, File);
		fwrite("\"cat\": \"function\",", 18, 1, File);
		fwrite("\"dur\": ", 7, 1, File);
		char* strDur = new char[16];
		_ui64toa(((Record.EndTime - Record.StartTime) * 1'000'000) / Record.Frequency, strDur, 10);
		fwrite(strDur, strlen(strDur), 1, File);
		SAFE_DELETE_ARR(strDur);
		fwrite(",", 1, 1, File);
		fwrite("\"name\": \"", 9, 1, File);
		fwrite(Record.ScopeName, strlen(Record.ScopeName), 1, File);
		fwrite("\",", 2, 1, File);
		fwrite("\"ph\":\"X\",", 9, 1, File);
		fwrite("\"pid\":0,", 8, 1, File);
		fwrite("\"tid\":0,", 8, 1, File);
		fwrite("\"ts\": ", 6, 1, File);
		char* strStart = new char[16];
		_ui64toa((Record.StartTime * 1'000'000) / Record.Frequency, strStart, 10);
		fwrite(strStart, strlen(strStart), 1, File);
		SAFE_DELETE_ARR(strStart);
		fwrite("}", 1, 1, File);
	}
	fwrite("\n]", 2, 1, File);

	fclose(File);
}
bool PerformanceProfiler::AddRecord(const ScopedRecord& Record)
{
	float ms = ((Record.EndTime - Record.StartTime) * 1000.0f) / Record.Frequency;
	DebugLog("Scope %s took %.1f ms.", Record.ScopeName, roundf(ms));

	ProfilerRecord Entry = {};

	Entry.ScopeName = Record.ScopeName;
	Entry.FileName = Record.FileName;
	Entry.Line = Record.Line;
	Entry.Frequency = Record.Frequency;
	Entry.StartTime = Record.StartTime;
	Entry.EndTime = Record.EndTime;

	Records.push_back(Entry);

	return true;
}
