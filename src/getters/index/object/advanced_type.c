/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json getters index object
*/

#include <error.h>
#include <getters/index/object.h>
#include <typedef/object.h>

int json_object_get_object_by_index(json_object_t const* object, size_t index,
                                    json_object_t const** value)
{
    json_object_element_t const* element = NULL;
    int ret = json_object_get_const_element_by_index_and_type(
        object, index, JSON_OBJ, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.obj;
    }
    return ret;
}

int json_object_get_array_by_index(json_object_t const* object, size_t index,
                                   json_array_t const** value)
{
    json_object_element_t const* element = NULL;
    int ret = json_object_get_const_element_by_index_and_type(
        object, index, JSON_ARRAY, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.array;
    }
    return ret;
}
