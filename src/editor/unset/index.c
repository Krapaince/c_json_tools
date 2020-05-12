/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor unset index
*/

#include <string.h>

#include <editor/destroy/union.h>
#include <error.h>
#include <typedef/array.h>
#include <typedef/object.h>

int json_object_unset_element_by_index(json_object_t* obj, size_t index)
{
    int ret;
    json_object_element_t* element;

    if (index < obj->len)
    {
        element = &obj->elements[index];
        json_union_value_destroy(&element->value, element->type);
        memmove(&obj->elements[index], &obj->elements[index + 1],
                (obj->len - (index + 1)) * sizeof(json_object_element_t));
        --obj->len;
        ret = 1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int json_array_unset_element_by_index(json_array_t* array, size_t index)
{
    int ret;
    json_array_element_t* element;

    if (index < array->len)
    {
        element = &array->elements[index];
        json_union_value_destroy(&element->value, element->type);
        memmove(&array->elements[index], &array->elements[index + 1],
                (array->len - (index + 1)) * sizeof(json_array_element_t));
        --array->len;
        ret = 1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}
