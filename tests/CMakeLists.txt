cmake_minimum_required(VERSION 3.19.2)

find_package(Criterion REQUIRED)


if (NOT Criterion_FOUND)
	return()
endif()

set(SRC_TEST
    editor/append.c
	editor/compare.c
	editor/extract/index/array.c
	editor/extract/index/object.c
	editor/extract/key/object.c
	editor/set/index/array.c
	editor/set/key/object.c
	editor/unset/index.c
	editor/unset/value/array.c
	editor/unset/object.c
	get_file_content.c
	generator/str.c
	getters/index/array.c
	getters/index/object.c
	getters/key/object.c
	getters/value/array.c
	parser/json_array_fd.c
	parser/json_array_filepath.c
	parser/json_array_str.c
	parser/json_obj_fd.c
	parser/json_obj_filepath.c
	parser/json_obj_str.c
	parser/strtok.c
	parser/token/flag/array.c
	parser/token/flag/object.c
)

set(BINARY_UNIT_TESTS "unit_tests")

add_executable(${BINARY_UNIT_TESTS} ${SRC_TEST})

target_link_libraries(${BINARY_UNIT_TESTS} ${LIB_JSON_TOOLS} ${CRITERION_LIBRARIES})

add_test(${BINARY_UNIT_TESTS} ${BINARY_UNIT_TESTS})

target_include_directories(${BINARY_UNIT_TESTS}
	PRIVATE
	include
)

file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/tests/output/obj)
file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/tests/output/array)

add_custom_command(
	TARGET ${BINARY_UNIT_TESTS}
	POST_BUILD
	COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${BINARY_UNIT_TESTS}
	WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
