/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor destroy object
*/

#include <stdlib.h>

#include <editor/destroy/union.h>
#include <typedef/object.h>

void json_object_destroy(json_object_t* obj)
{
    size_t i = 0;

    while (i < obj->len)
    {
        json_union_value_destroy(&obj->elements[i].value,
                                 obj->elements[i].type);
        free(obj->elements[i].key.value);
        ++i;
    }
    free(obj->elements);
    free(obj);
}
