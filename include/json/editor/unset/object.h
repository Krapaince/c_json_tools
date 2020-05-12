/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json editor unset object
*/

#ifndef JSON_EXPORT_EDITOR_UNSET_OBJECT_H_
#define JSON_EXPORT_EDITOR_UNSET_OBJECT_H_

#include <json/type/object.h>

// Unsets an element and remove it from the obj.
// Return the number of element(s) unsets.
size_t json_object_unset_element_by_key(json_object_t* obj, char const* key);

// Unsets an element and remove it from the obj.
// Return the number of element(s) unsets.
size_t json_object_unset_element_by_index(json_object_t* obj, size_t index);

#endif /* !JSON_EXPORT_EDITOR_UNSET_OBJECT_H_ */

