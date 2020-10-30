cmake_minimum_required(VERSION 3.11)

project(Engine)
set(PROJECT_NAME "PR310")

# includes after project declaration
# otherwise compiler id is unknown
include(compiler.cmake)

option(GENERATE_DOCS "Do you want to generate the documentation?" FALSE)

# ****************************************
# **** Add the included projects here ****
# ****************************************

add_subdirectory(shared)
add_subdirectory(driver.graphics)
add_subdirectory(engine.core)
add_subdirectory(pr310.game)
add_subdirectory(pr310.client)

if (GENERATE_DOCS)
	# generate directories
	add_custom_target("directories" ALL COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_SOURCE_DIR}/docs")

    # check if doxygen is available
    find_program(DOXY_EXECUTABLE doxygen DOC "doxygen generator")

    if(NOT DOXY_EXECUTABLE)
        message(SEND_ERROR "Cannot find doxygen.")
    endif(NOT DOXY_EXECUTABLE)
    
    # generate doxygen documentation
    configure_file(
        "${CMAKE_SOURCE_DIR}/conf/doxyfile.in"
        "${CMAKE_SOURCE_DIR}/docs/doxyfile" @ONLY)

    execute_process(
        COMMAND ${DOXY_EXECUTABLE} "${CMAKE_SOURCE_DIR}/docs/doxyfile"
        COMMENT "Generating documentation."
        VERBATIM
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/docs/")
endif()
