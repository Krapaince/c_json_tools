/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters type.h
*/

#ifndef JSON_GETTERS_TYPE_H_
#define JSON_GETTERS_TYPE_H_

#include <typedef/array.h>
#include <typedef/object.h>
#include <typedef/type.h>

// Compares the element_type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_does_element_is_type(json_type_t element_type, json_type_t type);

// Compares the element type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_object_does_element_is_type(json_object_element_t const* element,
                                      json_type_t type);

// Compares the element type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_array_does_element_is_type(json_array_element_t const* element,
                                     json_type_t type);

#endif /* !JSON_GETTERS_TYPE_H_ */
