#include <json/internal/editor/unset.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/object.h>

int json_array_unset_elements_by_value_object(json_array_t* array,
                                              json_object_t* value)
{
    json_array_element_t const element = {.type = JSON_OBJ, .value.obj = value};

    return json_array_unset_elements_by_value(array, &element);
}

int json_array_unset_elements_by_value_array(json_array_t* array,
                                             json_array_t* value)
{
    json_array_element_t const element = {.type = JSON_ARRAY,
                                          .value.array = value};

    return json_array_unset_elements_by_value(array, &element);
}
