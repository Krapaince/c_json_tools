/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json append array
*/

#ifndef JSON_EXPORT_APPEND_ARRAY_H_
#define JSON_EXPORT_APPEND_ARRAY_H_

#include <json/error.h>
#include <json/type/array.h>

// Adds an element of type JSON_BOOL at the end of the array.
// The array size is increase if the array is to small.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_append_bool(json_array_t* array, bool value);

// Adds an element of type JSON_NB at the end of the array.
// The array size is increase if the array is to small.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_append_nb(json_array_t* array, int value);

// Adds an element of type JSON_STR at the end of the array, duplicate value.
// The array size is increase if the array is to small.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_append_str_dup(json_array_t* array, char const* value);

// Adds an element of type JSON_STR at the end of the array.
// The function takes the pointer ownership.
// The array size is increase if the array is to small.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_append_str(json_array_t* array, char* value);

// Adds an element of type JSON_NULL at the end of the array.
// The array size is increase if the array is to small.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_append_null(json_array_t* array);

// Adds an element of type JSON_ARRAY at the end of the array.
// The function takes the pointer ownership.
// The array size is increase if the array is to small.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_append_array(json_array_t* array, json_array_t* value);

// Adds an element of type JSON_OBJ at the end of the array.
// The function takes the pointer ownership.
// The array size is increase if the array is to small.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_append_object(json_array_t* array, json_object_t* value);

#endif /* !JSON_EXPORT_APPEND_ARRAY_H_ */
