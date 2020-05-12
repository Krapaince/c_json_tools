/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters object
*/

#ifndef JSON_GETTERS_OBJECT_H_
#define JSON_GETTERS_OBJECT_H_

#include <typedef/object.h>

// Gets the element from the object and sets *element with it.
// If the index in out of the bound or the type doesn't match, the function
// fails and sets *element to NULL.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_object_get_const_element_by_index_and_type(
    json_object_t const* object, size_t index, json_type_t type,
    json_object_element_t const** element);

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
int json_object_get_element_by_key_and_type(json_object_t const* obj,
                                            char const* key, json_type_t type,
                                            json_object_element_t const** ptr);

#endif /* !JSON_GETTERS_OBJECT_H_ */
