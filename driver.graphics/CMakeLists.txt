# define project
project(driver.graphics C CXX)
SET(TARGET_NAME driver.graphics)

# configure executable, properties and linkage
add_library(${TARGET_NAME} STATIC)

# add sources to target
target_sources(
    ${TARGET_NAME}
    PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/rendererinterface.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/d3d11/d3d11renderer.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/d3d11/graphicsinterface.h"
    PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/src/d3d11/d3d11renderer.cpp"
)

# additional includes for target
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

# additional includes for target
target_include_directories(${TARGET_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/inc"
	"${CMAKE_SOURCE_DIR}/shared/inc"
)
