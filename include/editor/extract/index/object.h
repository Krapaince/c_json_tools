/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor extract object
*/

#ifndef JSON_EDITOR_EXTRACT_OBJECT_H_
#define JSON_EDITOR_EXTRACT_OBJECT_H_

#include <typedef/object.h>

// Extracts the element from the object and sets *element with it. The object's
// element is then set to null type. The ownership of the element's pointer is
// tranfered to the caller.
// If the index is out of the bound or the element's
// type at index doesn't match, the function fails and both *element and the
// array's element are left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_object_extract_element_by_index_and_type(
    json_object_t* object, size_t index, json_type_t type,
    json_object_element_t* element);

#endif /* !JSON_EDITOR_EXTRACT_OBJECT_H_ */
