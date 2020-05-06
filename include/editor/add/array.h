/*
** EPITECH PROJECT, 2020
** json library
** File description:
** add array
*/

#ifndef JSON_EDITOR_ADD_ARRAY_H_
#define JSON_EDITOR_ADD_ARRAY_H_

#include <typedef/array.h>

// Adds an element of type JSON_BOOL at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_bool(json_array_t* array, bool value);

// Adds an element of type JSON_NB at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_nb(json_array_t* array, int value);

// Adds an element of type JSON_STR at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_str_dup(json_array_t* array, char const* value);

// Adds an element of type JSON_STR at the end of the object.
// The function takes the pointer ownership on value.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_str(json_array_t* array, char* value);

// Adds an element of type JSON_NULL at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_null(json_array_t* array);

// Adds an element of type JSON_ARRAY at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_array(json_array_t* array, json_array_t* value);

// Adds an element of type JSON_OBJECT at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_object(json_array_t* array, json_object_t* value);

// Adds an element at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_array_add_element(json_array_t* array, json_array_element_t* element);

#endif /* !JSON_EDITOR_ADD_ARRAY_H_ */
