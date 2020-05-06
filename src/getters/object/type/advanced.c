/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters object type
*/

#include <getters/type.h>
#include <typedef/object.h>

bool json_object_does_element_is_an_array(json_object_element_t const* element)
{
    return json_object_does_element_is_type(element, JSON_ARRAY);
}

bool json_object_does_element_is_an_object(json_object_element_t const* element)
{
    return json_object_does_element_is_type(element, JSON_OBJ);
}
