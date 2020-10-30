
# check if msvc is defined else treat as gcc
if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC") # Microsoft Visual Studio C++ compiler
    set(CMAKE_CXX_FLAGS "/W3 /MP4 /DWIN32 /EHsc /D_WINDOWS /D_CRT_SECURE_NO_WARNINGS")
    set(CMAKE_CXX_FLAGS_DEBUG "/DENGINE_COMPILE_DEBUG /DAE_DEBUG_HEAP /guard:cf /W3 /WX /sdl /Zi /GR- /GS /permissive-")
    set(CMAKE_CXX_FLAGS_RELEASE "/DENGINE_COMPILE_RELEASE /W3 /WX /sdl /fp:fast /GF /GL /GR- /GS /Ox /Oi")

    set(CMAKE_EXE_LINKER_FLAGS "/NOLOGO /DYNAMICBASE")
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG "/DEBUG:FULL /INCREMENTAL")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/DEBUG:NONE /LTCG")

else() # GNU GCC compatible compiler
    set(CMAKE_CXX_FLAGS "-Wall")
    set(CMAKE_CXX_FLAGS_DEBUG "-D ENGINE_COMPILE_DEBUG -D AE_DEBUG_HEAP -fno-rtti -fno-jump-tables -ffunction-sections -fdata-sections -fstack-protector-strong")
    set(CMAKE_CXX_FLAGS_RELEASE "-D ENGINE_COMPILE_RELEASE -O3 -fno-rtti -fno-jump-tables -ffunction-sections -fdata-sections -fstack-protector-strong -s")
endif()

set(CMAKE_CXX_STANDARD 17)

# set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)
