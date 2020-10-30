// EXTERNAL INCLUDES
#include <cstdlib>

// INTERNAL INCLUDES
#include "application.h"
#include "basetypes.h"

u32 main(u32 argc, char** argv)
{
	Application App { };

	App.Initialize(argc, argv);
	App.Execute();
	App.Shutdown();

	exit(EXIT_SUCCESS);
}
