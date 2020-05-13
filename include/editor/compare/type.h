/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor compare type.h
*/

#ifndef JSON_EDITOR_COMPARE_TYPE_H_
#define JSON_EDITOR_COMPARE_TYPE_H_

#include <typedef/array.h>
#include <typedef/object.h>
#include <typedef/type.h>

// Compares element_type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_compare_element_type(json_type_t element_type, json_type_t type);

// Compares element type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_object_compare_element_type(json_object_element_t const* element,
                                      json_type_t type);

// Compares element type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_array_compare_element_type(json_array_element_t const* element,
                                     json_type_t type);

#endif /* !JSON_EDITOR_COMAPRE_TYPE_H_ */
