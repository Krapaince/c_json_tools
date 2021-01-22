cmake_minimum_required(VERSION 3.19.2)
project("c_json_tools")

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(Criterion REQUIRED)

if (NOT Criterion_FOUND)
	message(FATAL_ERROR "Criterion library not found! Aborting...")
endif()

if (CMAKE_COMPILER_IS_GNUCC)
	find_program(GCOVR_PRG gcovr REQUIRED)
	if (NOT GCOVR_PRG)
		message(FATAL_ERROR "Gcovr not found! Aborting...")
	endif()
endif()

# Include source of the project
include(src/CMakeLists.txt)
include(tests/CMakeLists.txt)

set(LIB_JSON_TOOLS "c-json-tools")
add_library(${LIB_JSON_TOOLS} STATIC ${SRC})
target_compile_options(${LIB_JSON_TOOLS} PRIVATE -Wall -Wextra)
target_include_directories(${LIB_JSON_TOOLS} PUBLIC include)

set(BINARY_UNIT_TESTS "unit_tests")
add_executable(${BINARY_UNIT_TESTS} ${SRC_TEST} ${SRC})

if (CMAKE_COMPILER_IS_GNUCC)
	target_compile_options(${BINARY_UNIT_TESTS} PRIVATE "--coverage")
	target_link_options(${BINARY_UNIT_TESTS} PRIVATE "--coverage")
	target_link_libraries(${BINARY_UNIT_TESTS} ${GCOV})
endif()
target_link_libraries(${BINARY_UNIT_TESTS} ${CRITERION_LIBRARIES})
add_test(${BINARY_UNIT_TESTS} ${BINARY_UNIT_TESTS})
target_include_directories(${BINARY_UNIT_TESTS}
	PRIVATE
	include
	tests/include
)

# Test fixture setup
add_custom_target(create_test_directories
	COMMAND ${CMAKE_COMMAND} -P ${PROJECT_SOURCE_DIR}/cmake/script/create_test_directories.cmake
		${PROJECT_SOURCE_DIR}
)

# Create coverage directory
add_custom_target(create_coverage_directories
	COMMAND ${CMAKE_COMMAND} -P ${PROJECT_SOURCE_DIR}/cmake/script/create_coverage_directory.cmake
		${CMAKE_BINARY_DIR}
)

# Run unit tests
add_custom_target( tests_run COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${BINARY_UNIT_TESTS}
	DEPENDS ${BINARY_UNIT_TESTS} create_test_directories
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

if (CMAKE_COMPILER_IS_GNUCC)
	add_custom_target(
		coverage
		COMMAND ${GCOVR_PRG}
			-r ${PROJECT_SOURCE_DIR}/src
			${CMAKE_CURRENT_BINARY_DIR}/CMakeFiles/${BINARY_UNIT_TESTS}.dir/src
			-e ${PROJECT_SOURCE_DIR}/tests
			--html --html-details --html-title ${PROJECT_NAME}
			-o ${CMAKE_CURRENT_BINARY_DIR}/coverage/${PROJECT_NAME}.html
		DEPENDS tests_run create_coverage_directories
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
	)
endif()

option(BUILD_DOC "Build project documentation" OFF)

if (BUILD_DOC)
    add_subdirectory(doc)
endif()
