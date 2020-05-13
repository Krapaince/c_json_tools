/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters object index
*/

#include <editor/compare/type.h>
#include <error.h>
#include <getters/index/object.h>
#include <typedef/object.h>

int json_object_extract_element_by_index_and_type(
    json_object_t* object, size_t index, json_type_t type,
    json_object_element_t* element)
{
    json_object_element_t* found_elem = NULL;
    int ret = json_object_get_element_by_index(object, index, &found_elem);

    if (ret == JSON_EXIT_SUCCESS)
    {
        if (json_object_compare_element_type(found_elem, type))
        {
            element->type = found_elem->type;
            element->value = found_elem->value;
            found_elem->type = JSON_NULL;
            found_elem->value.null = NULL;
        }
        else
        {
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}
