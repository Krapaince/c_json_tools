/*
** EPITECH PROJECT, 2020
** json library
** File description:
** append array.c
*/

#include <stdlib.h>

#include <error.h>
#include <typedef/array.h>

static int json_array_increase_size(json_array_t* array)
{
    int ret;
    size_t const nb_value_add = 25;
    size_t const size = array->len_alloc + nb_value_add;
    json_array_element_t* values =
        realloc(array->elements, sizeof(json_array_element_t) * size);

    if (values == NULL)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        array->elements = values;
        array->len_alloc = size;
        ret = JSON_EXIT_SUCCESS;
    }
    return ret;
}

int json_array_add_element(json_array_t* array, json_array_element_t* element)
{
    int ret = JSON_EXIT_SUCCESS;

    if (array->len_alloc <= array->len)
    {
        ret = json_array_increase_size(array);
    }
    if (ret == JSON_EXIT_SUCCESS)
    {
        array->elements[array->len] = *element;
        ++array->len;
    }
    return ret;
}
