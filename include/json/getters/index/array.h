/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json getters index array
*/

#ifndef JSON_EXPORT_GETTERS_INDEX_ARRAY_H_
#define JSON_EXPORT_GETTERS_INDEX_ARRAY_H_

#include <json/error.h>
#include <json/type/array.h>

// Gets the value from the array and sets *value with it.
// If the index in out of the bound or the type doesn't match, the function
// fails.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
int json_array_get_bool_by_index(json_array_t const* array, size_t index,
                                 bool* value);

// Gets the value from the array and sets *value with it.
// If the index in out of the bound or the type doesn't match, the function
// fails.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
int json_array_get_nb_by_index(json_array_t const* array, size_t index,
                               int* value);

// Gets the value from the array and sets *value with it.
// If the index in out of the bound or the type doesn't match, the function
// fails.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
int json_array_get_str_by_index(json_array_t const* array, size_t index,
                                str_t const** value);

// Gets the value from the array and sets *value with it.
// If the index in out of the bound or the type doesn't match, the function
// fails.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
int json_array_get_null_by_index(json_array_t const* array, size_t index,
                                 void const** value);

// Gets the value from the array and sets *value with it.
// If the index in out of the bound or the type doesn't match, the function
// fails.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
int json_array_get_object_by_index(json_array_t const* array, size_t index,
                                   json_object_t const** value);

// Gets the value from the array and sets *value with it.
// If the index in out of the bound or the type doesn't match, the function
// fails.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
int json_array_get_array_by_index(json_array_t const* array, size_t index,
                                  json_array_t const** value);

#endif /* !JSON_EXPORT_GETTERS_INDEX_ARRAY_H_ */

