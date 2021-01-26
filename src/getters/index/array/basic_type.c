#include <json/internal/error.h>
#include <json/internal/getters/index/array.h>
#include <json/internal/typedef/array.h>

int json_array_get_bool_by_index(json_array_t const* array, size_t index,
                                 bool* value)
{
    json_array_element_t const* element = NULL;
    int ret = json_array_get_const_element_by_index_and_type(
        array, index, JSON_BOOL, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.boolean;
    }
    return ret;
}

int json_array_get_nb_by_index(json_array_t const* array, size_t index,
                               int* value)
{
    json_array_element_t const* element = NULL;
    int ret = json_array_get_const_element_by_index_and_type(array, index,
                                                             JSON_NB, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.nb;
    }
    return ret;
}

int json_array_get_str_by_index(json_array_t const* array, size_t index,
                                str_t const** value)
{
    json_array_element_t const* element = NULL;
    int ret = json_array_get_const_element_by_index_and_type(
        array, index, JSON_STR, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = &element->value.str;
    }
    return ret;
}

int json_array_get_null_by_index(json_array_t const* array, size_t index,
                                 void const** value)
{
    json_array_element_t const* element = NULL;
    int ret = json_array_get_const_element_by_index_and_type(
        array, index, JSON_NULL, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.null;
    }
    return ret;
}
