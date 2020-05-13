/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json editor extract index array
*/

#ifndef JSON_EXPORT_EDITOR_EXTRACT_INDEX_ARRAY_H_
#define JSON_EXPORT_EDITOR_EXTRACT_INDEX_ARRAY_H_

#include <json/error.h>
#include <json/type/array.h>

// Extracts the value from the array and sets *value with it. The array's value
// is then set to null type.
// If the index is out of the bound or the value's type at index
// doesn't match, the function fails and both *value and the array's value are
// left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_extract_bool_by_index(json_array_t* array, size_t index,
                                     bool* value);

// Extracts the value from the array and sets *value with it. The array's value
// is then set to null type.
// If the index is out of the bound or the value's type at index
// doesn't match, the function fails and both *value and the array's value are
// left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_extract_nb_by_index(json_array_t* array, size_t index,
                                   int* value);

// Extracts the value from the array and sets *value with it. The array's value
// is then set to null type. The ownership of the value's pointer is tranfered
// to the caller.
// If the index is out of the bound or the value's type at index
// doesn't match, the function fails and both *value and the array's value are
// left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_extract_string_by_index(json_array_t* array, size_t index,
                                       char** value);

// Extracts the value from the array and sets *value with it. The array's value
// is then set to null type. The ownership of the value->value's pointer is
// tranfered to the caller.
// If the index is out of the bound or the value's type
// at index doesn't match, the function fails and both *value and the array's
// value are left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_extract_str_by_index(json_array_t* array, size_t index,
                                    str_t* value);

// Extracts the value from the array and sets *value with it. The array's value
// is then set to null type. The ownership of the value's pointer is tranfered
// to the caller.
// If the index is out of the bound or the value's type at index
// doesn't match, the function fails and both *value and the array's value are
// left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_extract_object_by_index(json_array_t* array, size_t index,
                                       json_object_t** value);

// Extracts the value from the array and sets *value with it. The array's value
// is then set to null type. The ownership of the value's pointer is tranfered
// to the caller.
// If the index is out of the bound or the value's type at index
// doesn't match, the function fails and both *value and the array's value are
// left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_extract_array_by_index(json_array_t* array, size_t index,
                                      json_array_t** value);

#endif /* !JSON_EXPORT_EDITOR_EXTRACT_INDEX_ARRAY_H_ */
