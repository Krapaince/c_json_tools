/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor set index array advanced_type
*/

#include <editor/destroy/union.h>
#include <error.h>
#include <typedef/array.h>

int json_array_set_object_by_index(json_array_t* array, size_t index,
                                   json_object_t* value)
{
    int ret;
    json_array_element_t* element;

    if (index < array->len)
    {
        element = &array->elements[index];
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_OBJ;
        element->value.obj = value;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_array_set_array_by_index(json_array_t* array, size_t index,
                                  json_array_t* value)
{
    int ret;
    json_array_element_t* element;

    if (index < array->len)
    {
        element = &array->elements[index];
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_ARRAY;
        element->value.array = value;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}
