#include <stdlib.h>
#include <string.h>

#include <json/internal/editor/add/array.h>
#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

int json_array_append_bool(json_array_t* array, bool value)
{
    return json_array_add_bool(array, value);
}

int json_array_append_nb(json_array_t* array, int value)
{
    return json_array_add_nb(array, value);
}

int json_array_append_str_dup(json_array_t* array, char const* value)
{
    return json_array_add_str_dup(array, value);
}

int json_array_append_str(json_array_t* array, char* value)
{
    return json_array_add_str(array, value);
}

int json_array_append_null(json_array_t* array)
{
    return json_array_add_null(array);
}
