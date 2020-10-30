# define project
project(engine.client C CXX)
SET(TARGET_NAME engine.core)

cmake_minimum_required (VERSION 3.9)

# Add source to this project's executable.
add_executable(${TARGET_NAME} "../res/appicon.ico" "../res/resources.rc")

# add sources to target
target_sources(
    ${TARGET_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/client.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/appwindow.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/d3d11renderer.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/camera.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/material.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/meshrenderer.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/shadercb.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/stb_image.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/flycamera.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/client.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/appwindow.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/d3d11renderer.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/camera.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/meshrenderer.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/flycamera.cpp"
)

# set additional target properties
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

# link libraries against the target
target_link_libraries(${TARGET_NAME}
    engine.shared
    D3D11 DXGI D3DCompiler)

# additional includes for target
target_include_directories(
    ${TARGET_NAME}
    PRIVATE
    "${CMAKE_SOURCE_DIR}/engine.shared/inc"
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)
