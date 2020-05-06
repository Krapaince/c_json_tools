/*
** EPITECH PROJECT, 2020
** json libraru
** File description:
** getters type array
*/

#include <getters/type.h>
#include <typedef/array.h>

bool json_array_does_element_is_a_bool(json_array_element_t const* element)
{
    return json_array_does_element_is_type(element, JSON_BOOL);
}

bool json_array_does_element_is_a_nb(json_array_element_t const* element)
{
    return json_array_does_element_is_type(element, JSON_NB);
}

bool json_array_does_element_is_a_str(json_array_element_t const* element)
{
    return json_array_does_element_is_type(element, JSON_STR);
}

bool json_array_does_element_is_a_null(json_array_element_t const* element)
{
    return json_array_does_element_is_type(element, JSON_NULL);
}
