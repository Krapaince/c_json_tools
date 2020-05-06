/*
** EPITECH PROJECT, 2020
** json library
** File description:
** basic type json
*/

#include <getters/type.h>
#include <typedef/object.h>
#include <typedef/type.h>

bool json_object_does_element_is_a_bool(json_object_element_t const* element)
{
    return json_object_does_element_is_type(element, JSON_BOOL);
}

bool json_object_does_element_is_a_nb(json_object_element_t const* element)
{
    return json_object_does_element_is_type(element, JSON_NB);
}

bool json_object_does_element_is_a_str(json_object_element_t const* element)
{
    return json_object_does_element_is_type(element, JSON_STR);
}

bool json_object_does_element_is_a_null(json_object_element_t const* element)
{
    return json_object_does_element_is_type(element, JSON_NULL);
}
