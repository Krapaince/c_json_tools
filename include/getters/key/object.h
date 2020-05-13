/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters key object
*/

#ifndef JSON_GETTERS_KEY_OBJECT_H_
#define JSON_GETTERS_KEY_OBJECT_H_

#include <typedef/object.h>

// Gets the element corresponding to the key. If there isn't any
// element corresponding to the key, the function fails. Otherwise
// *index is set and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_index_by_key(json_object_t const* obj, char const* key,
                                 size_t* index);

// Gets the element corresponding to the key. If there isn't any
// element corresponding, ptr is set to null and the function fails. Otherwise
// the ptr is set with the element and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_const_element_by_key(json_object_t const* obj,
                                         char const* key,
                                         json_object_element_t const** ptr);

// Gets the element corresponding to the key and the type. If there isn't any
// element corresponding, ptr is set to null and the function fails. Otherwise
// the ptr is set with the element and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_const_element_by_key_and_type(
    json_object_t const* obj, char const* key, json_type_t type,
    json_object_element_t const** ptr);

// Gets the element corresponding to the key. If there isn't any
// element corresponding, ptr is set to null and the function fails. Otherwise
// the *ptr is set with the element and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_element_by_key(json_object_t* obj, char const* key,
                                   json_object_element_t** ptr);

// Gets the element corresponding to the key and the type. If there isn't any
// element corresponding, ptr is set to null and the function fails. Otherwise
// the ptr is set with the element and the function success.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_get_element_by_key_and_type(json_object_t* obj, char const* key,
                                            json_type_t type,
                                            json_object_element_t** ptr);

#endif /* !JSON_GETTERS_KEY_OBJECT_H_ */
