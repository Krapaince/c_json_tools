/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor unset
*/

#ifndef JSON_EDITOR_UNSET_H_
#define JSON_EDITOR_UNSET_H_

#include <typedef/array.h>

// Unsets elements in the array matching the value.
// Return the number of element(s) unsets.
size_t json_array_unset_elements_by_value(json_array_t* array,
                                          json_array_element_t const* element);

#endif /* !JSON_EDITOR_UNSET_H_ */
