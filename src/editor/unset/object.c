/*
** EPITECH PROJECT, 2020
** json library
** File description:
** FileDescription
*/

#include <string.h>

#include <editor/destroy/union.h>
#include <error.h>
#include <getters/object.h>
#include <typedef/object.h>

int json_object_unset_element_by_key(json_object_t* obj, char const* key)
{
    size_t index;
    json_object_element_t* element;

    if (json_object_get_index_by_key(obj, key, &index) == JSON_EXIT_FAILURE)
    {
        return JSON_EXIT_FAILURE;
    }
    element = &obj->elements[index];
    json_union_value_destroy(&element->value, element->type);
    memmove(&obj->elements[index], &obj->elements[index + 1], obj->len - index);
    --obj->len;
    return JSON_EXIT_SUCCESS;
}
