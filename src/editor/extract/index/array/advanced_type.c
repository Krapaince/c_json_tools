/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor extract index array advanced_type
*/

#include <editor/extract/index/array.h>
#include <error.h>
#include <typedef/array.h>

int json_array_extract_object_by_index(json_array_t* array, size_t index,
                                       json_object_t** value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(array, index,
                                                           JSON_OBJ, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.obj;
    }
    return ret;
}

int json_array_extract_array_by_index(json_array_t* array, size_t index,
                                      json_array_t** value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(
        array, index, JSON_ARRAY, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.array;
    }
    return ret;
}
