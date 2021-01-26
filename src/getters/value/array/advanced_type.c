#include <json/internal/getters/value/array.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/object.h>

int json_array_get_index_by_object_value(json_array_t const* array,
                                         json_object_t* value, size_t* index)
{
    json_array_element_t const element = {.type = JSON_OBJ, .value.obj = value};

    return json_array_get_index_by_value_and_type(array, &element, index);
}

int json_array_get_index_by_array_value(json_array_t const* array,
                                        json_array_t* value, size_t* index)
{
    json_array_element_t const element = {.type = JSON_ARRAY,
                                          .value.array = value};

    return json_array_get_index_by_value_and_type(array, &element, index);
}
