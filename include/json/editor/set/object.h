/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor set object
*/

#ifndef JSON_EXPORT_EDITOR_SET_OBJECT_H_
#define JSON_EXPORT_EDITOR_SET_OBJECT_H_

#include <json/error.h>
#include <json/type/array.h>
#include <json/type/object.h>

// Sets the value to the key. If the key already exist the value is replace.
// Otherwise an element is created at the end of the object.
//
// If the function failed, the value if left untouched.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_set_bool_by_key(json_object_t* obj, char const* key,
                                bool value);

// Sets the value to the key. If the key already exist the value is replace.
// Otherwise an element is created at the end of the object.
//
// If the function failed, the value if left untouched.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_set_nb_by_key(json_object_t* obj, char const* key, int value);

// Sets the value to the key. If the key already exist the value is replace.
// Otherwise an element is created at the end of the object.
//
// If the function failed, the value if left untouched.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_set_str_dup_by_key(json_object_t* obj, char const* key,
                                   char const* value);

// Sets the value to the key. If the key already exist the value is replace.
// Otherwise an element is created at the end of the object.
//
// If the function failed, the value if left untouched.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_set_str_by_key(json_object_t* obj, char const* key,
                               char* value);

// Sets the value to the key. If the key already exist the value is replace.
// Otherwise an element is created at the end of the object.
//
// If the function failed, the value if left untouched.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_set_null_by_key(json_object_t* obj, char const* key);

// Sets the value to the key. If the key already exist the value is replace.
// Otherwise an element is created at the end of the object.
//
// If the function failed, the value if left untouched.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_set_object_by_key(json_object_t* obj, char const* key,
                                  json_object_t* value);

// Sets the value to the key. If the key already exist the value is replace.
// Otherwise an element is created at the end of the object.
//
// If the function failed, the value if left untouched.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_set_array_by_key(json_object_t* obj, char const* key,
                                 json_array_t* value);

#endif /* !JSON_EXPORT_EDITOR_SET_OBJECT_H_ */
