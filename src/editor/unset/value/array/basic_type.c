#include <string.h>

#include <json/internal/editor/unset.h>
#include <json/internal/typedef/array.h>

int json_array_unset_elements_by_value_bool(json_array_t* array, bool value)
{
    json_array_element_t const element = {.type = JSON_BOOL,
                                          .value.boolean = value};

    return json_array_unset_elements_by_value(array, &element);
}

int json_array_unset_elements_by_value_nb(json_array_t* array, int value)
{
    json_array_element_t const element = {.type = JSON_NB, .value.nb = value};

    return json_array_unset_elements_by_value(array, &element);
}

int json_array_unset_elements_by_value_str(json_array_t* array,
                                           str_t const* value)
{
    json_array_element_t const element = {.type = JSON_STR,
                                          .value.str = *value};

    return json_array_unset_elements_by_value(array, &element);
}

int json_array_unset_elements_by_null(json_array_t* array)
{
    json_array_element_t element = {.type = JSON_NULL, .value.null = NULL};

    return json_array_unset_elements_by_value(array, &element);
}
