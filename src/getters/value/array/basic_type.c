#include <string.h>

#include <json/internal/getters/value/array.h>
#include <json/internal/typedef/array.h>

int json_array_get_index_by_bool_value(json_array_t const* array, bool value,
                                       size_t* index)
{
    json_array_element_t const element = {.type = JSON_BOOL,
                                          .value.boolean = value};

    return json_array_get_index_by_value_and_type(array, &element, index);
}

int json_array_get_index_by_nb_value(json_array_t const* array, int value,
                                     size_t* index)
{
    json_array_element_t const element = {.type = JSON_NB, .value.nb = value};

    return json_array_get_index_by_value_and_type(array, &element, index);
}

int json_array_get_index_by_string_value(json_array_t const* array, char* value,
                                         size_t* index)
{
    json_array_element_t const element = {.type = JSON_STR,
                                          .value.str.value = value,
                                          .value.str.len = strlen(value)};

    return json_array_get_index_by_value_and_type(array, &element, index);
}

int json_array_get_index_by_str_value(json_array_t const* array, str_t* value,
                                      size_t* index)
{
    json_array_element_t const element = {.type = JSON_STR,
                                          .value.str = *value};

    return json_array_get_index_by_value_and_type(array, &element, index);
}

int json_array_get_index_by_null_value(json_array_t const* array, size_t* index)
{
    json_array_element_t const element = {.type = JSON_NULL,
                                          .value.null = NULL};

    return json_array_get_index_by_value_and_type(array, &element, index);
}
