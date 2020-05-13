/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json editor compare
*/

#ifndef JSON_EXPORT_EDITOR_COMAPRE_H_
#define JSON_EXPORT_EDITOR_COMAPRE_H_

#include <json/type/array.h>
#include <json/type/object.h>

// Compares the two objects.
//
// Return:
//   True if the objects are identical
//   False otherewise
//
bool json_object_compare(json_object_t const* obj1, json_object_t const* obj2);

// Compares the two arrays.
//
// Return:
//   True if the arrays are identical
//   False otherewise
//
bool json_array_compare(json_array_t const* array1, json_array_t const* array2);

#endif /* !JSON_EXPORT_EDITOR_COMAPRE_H_ */
