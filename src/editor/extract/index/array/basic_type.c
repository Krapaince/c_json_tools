#include <json/internal/editor/extract/index/array.h>
#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

int json_array_extract_bool_by_index(json_array_t* array, size_t index,
                                     bool* value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(array, index,
                                                           JSON_BOOL, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.boolean;
    }
    return ret;
}

int json_array_extract_nb_by_index(json_array_t* array, size_t index,
                                   int* value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(array, index,
                                                           JSON_NB, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.nb;
    }
    return ret;
}

int json_array_extract_string_by_index(json_array_t* array, size_t index,
                                       char** value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(array, index,
                                                           JSON_STR, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.str.value;
    }
    return ret;
}

int json_array_extract_str_by_index(json_array_t* array, size_t index,
                                    str_t* value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(array, index,
                                                           JSON_STR, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.str;
    }
    return ret;
}
