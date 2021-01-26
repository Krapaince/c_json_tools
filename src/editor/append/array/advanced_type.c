#include <string.h>

#include <json/internal/editor/add/array.h>
#include <json/internal/typedef/array.h>

int json_array_append_array(json_array_t* array, json_array_t* value)
{
    return json_array_add_array(array, value);
}

int json_array_append_object(json_array_t* array, json_object_t* value)
{
    return json_array_add_object(array, value);
}
