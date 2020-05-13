/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters value array
*/

#ifndef JSON_GETTERS_VALUE_ARRAY_H_
#define JSON_GETTERS_VALUE_ARRAY_H_

#include <error.h>
#include <typedef/array.h>

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

#endif /* !JSON_GETTERS_VALUE_ARRAY_H_ */
