/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json getters obj object
*/

#include <error.h>
#include <getters/object.h>
#include <getters/type.h>

int json_object_get_object_element_by_key(json_object_t const* obj,
                                          char const* key,
                                          json_object_element_t const** ptr)
{
    return json_object_get_element_by_key_and_type(obj, key, JSON_OBJ, ptr);
}

int json_object_get_object_value_by_key(json_object_t const* obj,
                                        char const* key,
                                        json_object_t const** ptr)
{
    json_object_element_t const* element;
    int ret = json_object_get_object_element_by_key(obj, key, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *ptr = element->value.obj;
    }
    return ret;
}
