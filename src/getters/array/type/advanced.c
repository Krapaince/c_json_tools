/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters type advanced
*/

#include <getters/type.h>
#include <typedef/object.h>

bool json_array_does_element_is_a_object(json_array_element_t const* element)
{
    return json_array_does_element_is_type(element, JSON_OBJ);
}

bool json_array_does_element_is_a_array(json_array_element_t const* element)
{
    return json_array_does_element_is_type(element, JSON_ARRAY);
}
