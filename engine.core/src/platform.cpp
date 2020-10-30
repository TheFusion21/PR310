// EXTERNAL INCLUDES
#include <Windows.h>
#include <intrin.h>
// INTERNAL INCLUDES
#include "basetypes.h"
#include "logging.h"
#include "platform.h"
#include "profiling/record.h"

AE_DEFINE_SINGLETON(PlatformHardware)

void PlatformHardware::OutputInfo()
{
	AE_FUNCTION_PROFILING();

	PlatformInfo PtInfo = { };
	PlatformHardware::GetPlatformInfo(PtInfo);

	AELog("----------- Hardware Information -----------");
	AELog("Number of processors: %i", PtInfo.NumProcessors);
	AELog("Max Physical Memory: %" PRIu64 " GB", static_cast<u64>(static_cast<double>(PtInfo.PhysicalMemory) * 1.073741824e-9));
	AELog("Max Virtual Memory: %" PRIu64 " GB", static_cast<u64>(static_cast<double>(PtInfo.VirtualMemory) * 1.073741824e-9));
	AELog("SSE Available: %s", PtInfo.SSEAvailable ? "Yes" : "No");
	AELog("SSE2 Available: %s", PtInfo.SSE2Available ? "Yes" : "No");
	AELog("SSE4 Available: %s", PtInfo.SSE4Available ? "Yes" : "No");
	AELog("--------------------------------------------");
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
