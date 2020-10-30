# define project
project(evenlight.client C CXX)
set(TARGET_NAME Client)

configure_file(
    "${CMAKE_SOURCE_DIR}/conf/appinfo.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/inc/appinfo.h" @ONLY)

# configure executable, properties and linkage
add_executable(
    ${TARGET_NAME}
    "res/appicon.ico"
    "res/resources.rc"
)

# add sources to target
target_sources(
    ${TARGET_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/appinfo.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/application.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/application.cpp"
)

# set additional target properties
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

# link libraries against the target
target_link_libraries(${TARGET_NAME}
    shared
    engine.driver.d3d11
    engine.core
    evenlight.game
    D3D11
    DXGI
    D3DCompiler)

# additional includes for target
target_include_directories(${TARGET_NAME} PRIVATE
	"${CMAKE_SOURCE_DIR}/shared/inc"
	"${CMAKE_SOURCE_DIR}/driver.d3d11/inc"
	"${CMAKE_SOURCE_DIR}/engine.core/inc"
	"${CMAKE_SOURCE_DIR}/evenlight.game/inc"
	"${CMAKE_CURRENT_SOURCE_DIR}/inc"
)

# generate directories
add_custom_target(
    "directories" ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/bin"
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/assets")
