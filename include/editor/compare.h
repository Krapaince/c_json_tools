/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor compare
*/

#ifndef JSON_EDITOR_COMPARE_H_
#define JSON_EDITOR_COMPARE_H_

#include <typedef/type.h>

bool json_compare_bool(bool first, bool second);
bool json_compare_nb(int first, int second);
bool json_compare_str(str_t const* first, str_t const* second);
bool json_compare_null(void const* first, void const* second);

// Compares the two elements.
//
// Return:
//   true - If the two elements are equal.
//   false otherewise.
bool json_compare_element(json_union_value_t const* value1, json_type_t type1,
                          json_union_value_t const* value2, json_type_t type2);

#endif /* !JSON_EDITOR_COMPARE_H_ */
