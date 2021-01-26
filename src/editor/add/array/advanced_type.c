#include <string.h>

#include <json/internal/editor/add/array.h>
#include <json/internal/typedef/array.h>

int json_array_add_array(json_array_t* array, json_array_t* value)
{
    json_array_element_t element;

    element.type = JSON_ARRAY;
    element.value.array = value;
    return json_array_add_element(array, &element);
}

int json_array_add_object(json_array_t* array, json_object_t* value)
{
    json_array_element_t element;

    element.type = JSON_OBJ;
    element.value.obj = value;
    return json_array_add_element(array, &element);
}
