/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters for a json object
*/

#include <string.h>

#include <error.h>
#include <getters/type.h>
#include <typedef/object.h>

int json_object_get_index_by_key(json_object_t const* obj, char const* key,
                                 size_t* index)
{
    size_t i = 0;

    while (i < obj->len)
    {
        if (strcmp(obj->elements[i].key.value, key) == 0)
        {
            *index = i;
            return JSON_EXIT_SUCCESS;
        }
        ++i;
    }
    return JSON_EXIT_FAILURE;
}

int json_object_get_const_element_by_key(json_object_t const* obj,
                                         char const* key,
                                         json_object_element_t const** ptr)
{
    size_t index;
    int ret = json_object_get_index_by_key(obj, key, &index);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *ptr = &obj->elements[index];
    }
    else
    {
        *ptr = NULL;
    }
    return ret;
}

int json_object_get_element_by_key(json_object_t* obj, char const* key,
                                   json_object_element_t** ptr)
{
    size_t index;
    int ret = json_object_get_index_by_key(obj, key, &index);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *ptr = &obj->elements[index];
    }
    else
    {
        *ptr = NULL;
    }
    return ret;
}

int json_object_get_element_by_key_and_type(json_object_t const* obj,
                                            char const* key, json_type_t type,
                                            json_object_element_t const** ptr)
{
    int ret = json_object_get_const_element_by_key(obj, key, ptr);

    if (ret == JSON_EXIT_SUCCESS)
    {
        if (json_object_does_element_is_type(*ptr, type) == false)
        {
            *ptr = NULL;
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}

bool json_object_does_key_exist(json_object_t const* obj, char const* key)
{
    json_object_element_t const* element = NULL;

    json_object_get_const_element_by_key(obj, key, &element);
    return element != NULL;
}
