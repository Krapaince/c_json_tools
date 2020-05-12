/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters array index
*/

#include <error.h>
#include <typedef/array.h>

static int json_array_get_const_element_by_index(
    json_array_t const* array, size_t index,
    json_array_element_t const** element)
{
    int ret;

    if (index < array->len)
    {
        *element = &array->elements[index];
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        *element = NULL;
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_array_get_const_element_by_index_and_type(
    json_array_t const* array, size_t index, json_type_t type,
    json_array_element_t const** element)
{
    int ret = json_array_get_const_element_by_index(array, index, element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        if ((*element)->type != type)
        {
            *element = NULL;
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}
