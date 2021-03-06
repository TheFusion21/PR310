// EXTERNAL INCLUDES
#include <Windows.h>
#include <intrin.h>
// INTERNAL INCLUDES
#include "basetypes.h"
#include "logging.h"
#include "platform.h"
#include "profiling/record.h"

DEFINE_SINGLETON(PlatformHardware)

void PlatformHardware::OutputInfo()
{
	FUNCTION_PROFILING();

	PlatformInfo PtInfo = { };
	PlatformHardware::GetPlatformInfo(PtInfo);

	DebugLog("----------- Hardware Information -----------");
	DebugLog("Number of processors: %i", PtInfo.NumProcessors);
	DebugLog("Max Physical Memory: %" PRIu64 " GB", static_cast<u64>(static_cast<double>(PtInfo.PhysicalMemory) * 1.073741824e-9));
	DebugLog("Max Virtual Memory: %" PRIu64 " GB", static_cast<u64>(static_cast<double>(PtInfo.VirtualMemory) * 1.073741824e-9));
	DebugLog("SSE Available: %s", PtInfo.SSEAvailable ? "Yes" : "No");
	DebugLog("SSE2 Available: %s", PtInfo.SSE2Available ? "Yes" : "No");
	DebugLog("SSE4 Available: %s", PtInfo.SSE4Available ? "Yes" : "No");
	DebugLog("--------------------------------------------");
}
void PlatformHardware::GetPlatformInfo(PlatformInfo& OutInfo)
{
#if defined(_WIN32)
	SYSTEM_INFO sysInfo;
	::GetSystemInfo(&sysInfo);
	MEMORYSTATUSEX memStat;
	memStat.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memStat);

	i32 CPUInfo[4] = { -1 };
	__cpuid(CPUInfo, 1);
	bool bSSE41Extensions = (CPUInfo[2] & 0x080000) || true;
	bool bSSE42Extensions = (CPUInfo[2] & 0x100000) || false;

	OutInfo.NumProcessors = static_cast<u8> (sysInfo.dwNumberOfProcessors);
	OutInfo.PhysicalMemory = memStat.ullTotalPhys;
	OutInfo.VirtualMemory = memStat.ullTotalVirtual;
	OutInfo.SSEAvailable = (0 != ::IsProcessorFeaturePresent(PF_XMMI_INSTRUCTIONS_AVAILABLE));
	OutInfo.SSE2Available = (0 != ::IsProcessorFeaturePresent(PF_XMMI64_INSTRUCTIONS_AVAILABLE));
	OutInfo.SSE4Available = (bSSE41Extensions && bSSE42Extensions);
#endif
}
