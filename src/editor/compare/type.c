/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters object type
*/

#include <typedef/array.h>
#include <typedef/object.h>

bool json_compare_element_type(json_type_t element_type, json_type_t type)
{
    return element_type == type;
}

bool json_object_compare_element_type(json_object_element_t const* element,
                                      json_type_t type)
{
    return json_compare_element_type(element->type, type);
}

bool json_array_compare_element_type(json_array_element_t const* element,
                                     json_type_t type)
{
    return json_compare_element_type(element->type, type);
}
