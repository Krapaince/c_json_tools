/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json append object
*/

#ifndef JSON_EXPORT_APPEND_OBJECT_H_
#define JSON_EXPORT_APPEND_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

// Adds an element of type JSON_BOOL at the end of the object.
// If the key already exist in the object the function fails and json_errno is
// set to JSON_E_KEY_ALREADY_EXIST.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_append_bool(json_object_t* obj, char const* key, bool value);

// Adds an element of type JSON_NB at the end of the object.
// If the key already exist in the object the function fails and json_errno is
// set to JSON_E_KEY_ALREADY_EXIST.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_append_nb(json_object_t* obj, char const* key, int value);

// Adds an element of type JSON_STR at the end of the object, duplicate value.
// The function fails if key already exist in obj.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_append_str_dup(json_object_t* obj, char const* key,
                               char const* value);

// Adds an element of type JSON_STR at the end of the object.
// The function takes the pointer ownership on value.
// The function fails if key already exist in obj.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_append_str(json_object_t* obj, char const* key, char* value);

// Adds an element of type JSON_NULL at the end of the object.
// If the key already exist in the object the function fails and json_errno is
// set to JSON_E_KEY_ALREADY_EXIST.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_append_null(json_object_t* obj, char const* key);

// Adds an element of type JSON_OBJECT at the end of the object.
// The function takes the pointer ownership.
// The function fails if key already exist in obj.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_append_object(json_object_t* obj, char const* key,
                              json_object_t* value);

// Adds an element of type JSON_ARRAY at the end of the object.
// The function takes the pointer ownership.
// The function fails if key already exist in obj.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_append_array(json_object_t* obj, char const* key,
                             json_array_t* value);

#endif /* !JSON_EXPORT_APPEND_OBJECT_H_ */
