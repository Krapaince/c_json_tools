/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor destroy union
*/

#include <stdlib.h>

#include <json/editor/destroy.h>
#include <typedef/array.h>
#include <typedef/object.h>

void json_union_value_destroy(json_union_value_t* value, json_type_t type)
{
    switch (type)
    {
        case JSON_ARRAY:
            json_array_destroy(value->array);
            break;
        case JSON_OBJ:
            json_object_destroy(value->obj);
            break;
        case JSON_STR:
            free(value->str.value);
            break;
        default:
            break;
    }
}
