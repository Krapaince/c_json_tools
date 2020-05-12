/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters array
*/

#ifndef JSON_GETTERS_ARRAY_H_
#define JSON_GETTERS_ARRAY_H_

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

// Gets the index by searching through the array for element and sets *index
// with the found element index. If the element doesn't match any in array the
// function fails.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_value_and_type(json_array_t const* array,
                                           json_array_element_t const* element,
                                           size_t* index);

#endif /* !JSON_GETTERS_ARRAY_H_ */

