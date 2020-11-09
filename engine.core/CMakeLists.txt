# define project
project(engine.core C CXX)
SET(TARGET_NAME engine.core)

# configure executable, properties and linkage
add_library(${TARGET_NAME} STATIC)

# add sources to target
target_sources(${TARGET_NAME}
	PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/engine.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/platform.h"


		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/component/componentarray.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/component/componentpool.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/component/transform.h"

		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/entity/entity.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/entity/entitypool.h"

		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/system/system.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/system/systempool.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/ecs/system/testsystem.h"
	PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/src/engine.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/platform.cpp"
	)

# additional includes for target
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

# define the include directories
target_include_directories(${TARGET_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/inc"
	"${CMAKE_SOURCE_DIR}/shared/inc")
