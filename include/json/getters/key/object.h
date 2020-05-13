/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters index object
*/

#ifndef JSON_EXPORT_GETTERS_KEY_OBJECT_H_
#define JSON_EXPORT_GETTERS_KEY_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

// Gets the element corresponding to the key. If there isn't any
// element corresponding, value is set to null and the function fails. Otherwise
// the *value is set with the element and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_const_element_by_key(json_object_t const* obj,
                                         char const* key,
                                         json_object_element_t const** value);

// Gets the value corresponding to the key and the type JSON_NB. If there
// isn't any value corresponding, value is set to null and the function fails.
// Otherwise the value is set with the value and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_bool_by_key(json_object_t const* obj, char const* key,
                                bool* value);

// Gets the value corresponding to the key and the type JSON_NB. If there
// isn't any value corresponding, value is set to null and the function fails.
// Otherwise the value is set with the value and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_nb_by_key(json_object_t const* obj, char const* key,
                              int* value);

// Gets the value corresponding to the key and the type JSON_NULL. If there
// isn't any value corresponding, value is set to null and the function fails.
// Otherwise the value is set with the value and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_null_by_key(json_object_t const* obj, char const* key,
                                void const** value);

// Gets the value corresponding to the key and the type JSON_STR. If there
// isn't any value corresponding, value is set to null and the function fails.
// Otherwise the value is set with the value and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_string_by_key(json_object_t const* obj, char const* key,
                                  char const** value);

// Gets the value corresponding to the key and the type JSON_STR. If there
// isn't any value corresponding, value is set to null and the function fails.
// Otherwise the value is set with the value and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_str_by_key(json_object_t const* obj, char const* key,
                               str_t const** value);

// Gets the value corresponding to the key and the type JSON_OBJ. If there
// isn't any value corresponding, value is set to null and the function fails.
// Otherwise the value is set with the value and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_object_by_key(json_object_t const* obj, char const* key,
                                  json_object_t const** value);

// Gets the value corresponding to the key and the type JSON_ARRAY. If there
// isn't any value corresponding, value is set to null and the function fails.
// Otherwise the value is set with the value and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_array_by_key(json_object_t const* obj, char const* key,
                                 json_array_t const** value);

// Check if key correspond with an element of the object.
// The caller should not send a NULL value.
//
// Return:
//   TRUE if it match with an alement
//   FALSE if it haven't match with an element
bool json_object_does_key_exist(json_object_t const* obj, char const* key);

#endif /* !JSON_EXPORT_GETTERS_KEY_OBJECT_H_ */
