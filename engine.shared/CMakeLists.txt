# define project
project(engine.shared C CXX)
SET(TARGET_NAME engine.shared)

# configure executable, properties and linkage
add_library(${TARGET_NAME} STATIC)

# add sources to target
target_sources(
    ${TARGET_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/math/mathutils.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/math/quaternion.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/math/mat4x4.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/math/vec3.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/math/vec2.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/appinfo.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/types.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/util.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/color.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/singleton.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/transform.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/time.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/vertex.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/gameobject.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/component.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/mesh.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/inc/input.h"
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/src/math/vec3.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/math/vec2.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/math/mat4x4.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/math/quaternion.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/time.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/gameobject.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/component.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/mesh.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/transform.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/input.cpp"
)

# set additional target properties
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX DEBUG_POSTFIX ".debug")

target_include_directories(
    ${TARGET_NAME}
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/inc"
)