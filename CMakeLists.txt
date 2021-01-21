cmake_minimum_required(VERSION 3.19.2)
project("krapaince_c_json_tools")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Include source of the project
include(src/CMakeLists.txt)

set(INCLUDE include)

set(LIB_JSON_TOOLS "krapaince-c-json-tools")

add_library(${LIB_JSON_TOOLS} STATIC ${SRC})

set(CMAKE_C_FLAGS "-Wall -Wextra")

target_include_directories(${LIB_JSON_TOOLS} PUBLIC
    include
)

option(BUILD_DOC "Build project documentation" OFF)
option(BUILD_TESTS "Build project test" ON)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()

if (BUILD_DOC)
    add_subdirectory(doc)
endif()
