# define project
project(pr310.game C CXX)
set(TARGET_NAME pr310.game)

# configure executable, properties and linkage
add_library(${TARGET_NAME} STATIC)

# add the shader compiler as a custom target
add_custom_target(
	ShaderCompiler
	COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/shaders/shadercompiler.bat" "${CMAKE_BUILD_TYPE}"
	WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
	USES_TERMINAL
	COMMENT "Compiling shaders for Debug mode."
)

# set the shader compiler as a dependency for the compile process
add_dependencies(${TARGET_NAME} ShaderCompiler)

# add sources to target
target_sources(
    ${TARGET_NAME}
	PUBLIC
	PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/src/0.cpp")

# set additional target properties
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

# additional includes for target
target_include_directories(${TARGET_NAME} PRIVATE
	"${CMAKE_SOURCE_DIR}/shared/inc"
	"${CMAKE_SOURCE_DIR}/engine.core/inc"
	"${CMAKE_CURRENT_SOURCE_DIR}/inc"
)
