/*
** EPITECH PROJECT, 2020
** json library
** File description:
** destroy.c
*/

#include <stddef.h>
#include <stdlib.h>

#include <editor/destroy/union.h>
#include <typedef/array.h>

void json_array_destroy(json_array_t* array)
{
    size_t i = 0;

    while (i < array->len)
    {
        json_union_value_destroy(&array->elements[i].value,
                                 array->elements[i].type);
        ++i;
    }
    free(array->elements);
    free(array);
}
