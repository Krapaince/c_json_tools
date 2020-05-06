/*
** EPITECH PROJECT, 2020
** json library
** File description:
** object add basic_type
*/

#include <stdlib.h>
#include <string.h>

#include <editor/add/object.h>
#include <editor/key.h>
#include <error.h>
#include <typedef/object.h>

int json_object_add_bool(json_object_t* obj, char const* key, bool value)
{
    json_object_element_t element;
    int ret = JSON_EXIT_FAILURE;

    ret = json_assign_key_to_element(&element, key);
    if (ret == JSON_EXIT_SUCCESS)
    {
        element.type = JSON_BOOL;
        element.value.boolean = value;
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(element.key.value);
        }
    }
    return ret;
}

int json_object_add_nb(json_object_t* obj, char const* key, int value)
{
    json_object_element_t element;
    int ret = JSON_EXIT_FAILURE;

    ret = json_assign_key_to_element(&element, key);
    if (ret == JSON_EXIT_SUCCESS)
    {
        element.type = JSON_NB;
        element.value.nb = value;
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(element.key.value);
        }
    }
    return ret;
}

int json_object_add_str_dup(json_object_t* obj, char const* key,
                            char const* value)
{
    json_object_element_t element;
    int ret = json_assign_key_to_element(&element, key);

    if (ret != JSON_EXIT_SUCCESS)
    {
        return ret;
    }
    element.type = JSON_STR;
    element.value.str.len = strlen(value);
    element.value.str.value = strdup(value);
    if (element.value.str.value)
    {
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(element.key.value);
            free(element.value.str.value);
        }
    }
    else
    {
        free(element.key.value);
    }
    return ret;
}

int json_object_add_str(json_object_t* obj, char const* key, char* value)
{
    json_object_element_t element;
    int ret = json_assign_key_to_element(&element, key);

    if (ret != JSON_EXIT_SUCCESS)
    {
        return ret;
    }
    element.type = JSON_STR;
    element.value.str.len = strlen(value);
    element.value.str.value = value;
    ret = json_object_add_element(obj, &element);
    if (ret != JSON_EXIT_SUCCESS)
    {
        free(element.key.value);
    }
    return ret;
}

int json_object_add_null(json_object_t* obj, char const* key)
{
    json_object_element_t element;
    int ret = JSON_EXIT_FAILURE;

    ret = json_assign_key_to_element(&element, key);
    if (ret == JSON_EXIT_SUCCESS)
    {
        element.type = JSON_NULL;
        element.value.null = NULL;
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(element.key.value);
        }
    }
    return ret;
}
