/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json getter obj nb
*/

#include <error.h>
#include <getters/key/object.h>

int json_object_get_nb_element_by_key(json_object_t const* obj, char const* key,
                                      json_object_element_t const** ptr)
{
    return json_object_get_const_element_by_key_and_type(obj, key, JSON_NB,
                                                         ptr);
}

int json_object_get_nb_value_by_key(json_object_t const* obj, char const* key,
                                    int* ptr)
{
    json_object_element_t const* element;
    int ret = json_object_get_nb_element_by_key(obj, key, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *ptr = element->value.nb;
    }
    return ret;
}
