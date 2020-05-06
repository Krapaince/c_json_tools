/*
** EPITECH PROJECT, 2020
** json library
** File description:
** add object advanced type
*/

#include <stdlib.h>

#include <editor/add/object.h>
#include <editor/key.h>
#include <error.h>
#include <typedef/object.h>

int json_object_add_array(json_object_t* obj, char const* key,
                          json_array_t* value)
{
    json_object_element_t element;
    int ret = JSON_EXIT_FAILURE;

    ret = json_assign_key_to_element(&element, key);
    if (ret == JSON_EXIT_SUCCESS)
    {
        element.type = JSON_ARRAY;
        element.value.array = value;
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(element.key.value);
        }
    }
    return ret;
}

int json_object_add_object(json_object_t* obj, char const* key,
                           json_object_t* value)
{
    json_object_element_t element;
    int ret = JSON_EXIT_FAILURE;

    ret = json_assign_key_to_element(&element, key);
    if (ret == JSON_EXIT_SUCCESS)
    {
        element.type = JSON_OBJ;
        element.value.obj = value;
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(element.key.value);
        }
    }
    return ret;
}
