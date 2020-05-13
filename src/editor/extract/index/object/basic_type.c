/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters object index basic_type.c
*/

#include <editor/extract/index/object.h>
#include <error.h>
#include <typedef/object.h>

int json_object_extract_bool_by_index(json_object_t* object, size_t index,
                                      bool* value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_index_and_type(
        object, index, JSON_BOOL, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.boolean;
    }
    return ret;
}

int json_object_extract_nb_by_index(json_object_t* object, size_t index,
                                    int* value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_index_and_type(object, index,
                                                            JSON_NB, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.nb;
    }
    return ret;
}

int json_object_extract_string_by_index(json_object_t* object, size_t index,
                                        char** value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_index_and_type(object, index,
                                                            JSON_STR, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.str.value;
    }
    return ret;
}

int json_object_extract_str_by_index(json_object_t* object, size_t index,
                                     str_t* value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_index_and_type(object, index,
                                                            JSON_STR, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.str;
    }
    return ret;
}
