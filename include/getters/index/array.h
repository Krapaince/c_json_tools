/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters index array
*/

#ifndef JSON_GETTERS_INDEX_ARRAY_H_
#define JSON_GETTERS_INDEX_ARRAY_H_

#include <error.h>
#include <typedef/array.h>

// Gets the element from the array and sets *element with it.
// If the index in out of the bound or the type doesn't match, the function
// fails and sets *element to NULL.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_const_element_by_index_and_type(
    json_array_t const* array, size_t index, json_type_t type,
    json_array_element_t const** element);

// Gets the element from the array and sets *element with it.
// If the index in out of the bound doesn't match, the function
// fails and sets *element to NULL.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_element_by_index(json_array_t* array, size_t index,
                                    json_array_element_t** element);

#endif /* !JSON_GETTERS_INDEX_ARRAY_H_ */
