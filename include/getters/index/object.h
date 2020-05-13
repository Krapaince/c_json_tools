/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters index object
*/

#ifndef JSON_GETTERS_INDEX_OBJECT_H_
#define JSON_GETTERS_INDEX_OBJECT_H_

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

// Gets the element from the object and sets *element with it.
// If the index in out of the bound or the type doesn't match, the function
// fails and sets *element to NULL.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_object_get_element_by_index(json_object_t* object, size_t index,
                                     json_object_element_t** element);

#endif /* !JSON_GETTERS_INDEX_OBJECT_H_ */
