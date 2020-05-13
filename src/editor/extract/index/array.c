/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters array index
*/

#include <editor/compare/type.h>
#include <error.h>
#include <getters/index/array.h>
#include <typedef/array.h>

int json_array_extract_element_by_index_and_type(json_array_t* array,
                                                 size_t index, json_type_t type,
                                                 json_array_element_t* element)
{
    json_array_element_t* found_elem = NULL;
    int ret = json_array_get_element_by_index(array, index, &found_elem);

    if (ret == JSON_EXIT_SUCCESS)
    {
        if (json_array_compare_element_type(found_elem, type))
        {
            *element = *found_elem;
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
