cmake_minimum_required(VERSION 3.19.2)

find_package(Doxygen REQUIRED)
find_package(Sphinx REQUIRED)

if (NOT Doxygen_FOUND)
    message(FATAL_ERROR "Doxygen not found! Aborting...")
endif()

if (NOT Sphinx_FOUND)
    message(FATAL_ERROR "Sphinx not found! Aborting...")
endif()

get_target_property(LIB_JSON_HEADERS ${LIB_JSON_TOOLS} INTERFACE_INCLUDE_DIRECTORIES)

set(DOXYGEN_INPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/src ${LIB_JSON_HEADERS})
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Doxygen)
set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIRECTORY}/xml/index.xml)
set(DOXYGEN_INCLUDE_PATH ${LIB_JSON_TOOLS})
set(DOXYGEN_SEARCH_INCLUDES YES)
set(DOXYGEN_GENERATE_HTML NO)
set(DOXYGEN_GENERATE_XML YES)
set(DOXYGEN_FILE_PATTERNS *.c *.h)

file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIRECTORY})

doxygen_add_docs(Doxygen
                ${DOXYGEN_INPUT_DIRECTORY}
                COMMENT "Generating docs")

set(SPHINX_SOURCE ${PROJECT_SOURCE_DIR}/doc)
set(SPHINX_BUILD ${CMAKE_CURRENT_BINARY_DIR}/Sphinx)
set(SPHINX_INDEX_FILE ${SPHINX_BUILD}/index.html)

add_custom_command(OUTPUT ${SPHINX_INDEX_FILE}
    COMMAND
        ${SPHINX_EXECUTABLE} -b html
        # Tell breathe where to find Doxygen output
        -Dbreathe_projects.krapaince_c_json_tools=${DOXYGEN_OUTPUT_DIRECTORY}/xml
        ${SPHINX_SOURCE} ${SPHINX_BUILD}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS
        ${SPHINX_SOURCE}/index.rst
        ${DOXYGEN_INDEX_FILE}
        MAIN_DEPENDENCY ${SPHINX_SOURCE}/conf.py
        COMMENT "Generating documentation with Spinx")

add_custom_target(Sphinx ALL DEPENDS ${SPHINX_INDEX_FILE})
add_dependencies(Sphinx Doxygen)
