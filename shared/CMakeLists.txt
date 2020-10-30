# define project
project(shared C CXX)
SET(TARGET_NAME shared)

# configure executable, properties and linkage
add_library(${TARGET_NAME} STATIC)

# add sources to target
target_sources(
    ${TARGET_NAME}
    PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/basetypes.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/logging.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/singleton.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/math/color.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/math/mat4x4.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/math/quaternion.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/math/vec2.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/math/vec3.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/memory/memutils.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/profiling/profiler.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/inc/profiling/record.h"
    PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/src/math/color.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/math/mat4x4.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/math/quaternion.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/math/vec2.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/math/vec3.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/profiling/profiler.cpp"
		"${CMAKE_CURRENT_SOURCE_DIR}/src/profiling/record.cpp"
)

# set additional target properties
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

# additional includes for target
target_include_directories(${TARGET_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

# check if git is available
find_program(GIT_EXECUTABLE git ${PATH} DOC "git client")
if(NOT GIT_EXECUTABLE)
    message(SEND_ERROR "Cannot find git.")
endif(NOT GIT_EXECUTABLE)

# execute git version commands
execute_process(COMMAND
    "${GIT_EXECUTABLE}" describe --abbrev=0 --tags
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE GIT_TAG
    ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND
    "${GIT_EXECUTABLE}" log -1 --pretty=format:%h --no-show-signature
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE GIT_COMMIT
    ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)
execute_process(COMMAND
    "${GIT_EXECUTABLE}" log -1 --date=format:%Y-%m-%d\ %H:%M:%S --pretty=format:%ad --no-show-signature
    WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    OUTPUT_VARIABLE GIT_DATE
    ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE)

configure_file(
    "${CMAKE_SOURCE_DIR}/conf/version.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/inc/version.h" @ONLY)
