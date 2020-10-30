# define project
project(engine.driver.d3d11 C CXX)
SET(TARGET_NAME engine.driver.d3d11)

# configure executable, properties and linkage
add_library(${TARGET_NAME} STATIC)

# add sources to target
target_sources(
    ${TARGET_NAME}
    PUBLIC
    PRIVATE
		"${CMAKE_CURRENT_SOURCE_DIR}/src/0.cpp"
)

# additional includes for target
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

# additional includes for target
target_include_directories(${TARGET_NAME} PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/inc"
	"${CMAKE_SOURCE_DIR}/shared/inc"
)
