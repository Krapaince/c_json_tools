/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json getters obj object
*/

#include <error.h>
#include <getters/key/object.h>

int json_object_get_object_element_by_key(json_object_t const* obj,
                                          char const* key,
                                          json_object_element_t const** ptr)
{
    return json_object_get_const_element_by_key_and_type(obj, key, JSON_OBJ,
                                                         ptr);
}
