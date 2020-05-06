/*
** EPITECH PROJECT, 2020
** json library
** File description:
** append object basic type
*/

#include <stdlib.h>
#include <string.h>

#include <editor/add/object.h>
#include <editor/key.h>
#include <error.h>
#include <json/getters/object.h>
#include <typedef/object.h>

int json_object_append_array(json_object_t* obj, char const* key,
                             json_array_t* value)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_add_array(obj, key, value);
    }
    return ret;
}

int json_object_append_object(json_object_t* obj, char const* key,
                              json_object_t* value)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_add_object(obj, key, value);
    }
    return ret;
}
