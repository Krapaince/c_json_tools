/*
** EPITECH PROJECT, 2020
** json library
** File description:
** object set advanced_type
*/

#include <editor/add/object.h>
#include <editor/destroy/union.h>
#include <editor/key.h>
#include <error.h>
#include <getters/key/object.h>
#include <typedef/object.h>

int json_object_set_object_by_key(json_object_t* obj, char const* key,
                                  json_object_t* value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_OBJ;
        element->value.obj = value;
    }
    else
    {
        ret = json_object_add_object(obj, key, value);
    }
    return ret;
}

int json_object_set_array_by_key(json_object_t* obj, char const* key,
                                 json_array_t* value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_ARRAY;
        element->value.array = value;
    }
    else
    {
        ret = json_object_add_array(obj, key, value);
    }
    return ret;
}
