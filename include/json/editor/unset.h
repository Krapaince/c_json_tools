/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json object unset
*/

#ifndef JSON_EXPORT_EDITOR_UNSET_H_
#define JSON_EXPORT_EDITOR_UNSET_H_

#include <error.h>
#include <json/type/object.h>

// Unsets an element and remove it from the obj.
//
// Return:
//   JSON_EXIT_FAILURE if none element with as a key key have been found
//   JSON_EXIT_SUCCESS if an element have been remove
int json_object_unset_element_by_key(json_object_t* obj, char const* key);

#endif /* !JSON_EXPORT_EDITOR_UNSET_H_ */
