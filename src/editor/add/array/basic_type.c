#include <stdlib.h>
#include <string.h>

#include <json/internal/editor/add/array.h>
#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

int json_array_add_bool(json_array_t* array, bool value)
{
    json_array_element_t element;

    element.type = JSON_BOOL;
    element.value.boolean = value;
    return json_array_add_element(array, &element);
}

int json_array_add_nb(json_array_t* array, int value)
{
    json_array_element_t element;

    element.type = JSON_NB;
    element.value.nb = value;
    return json_array_add_element(array, &element);
}

int json_array_add_str_dup(json_array_t* array, char const* value)
{
    json_array_element_t element;
    int ret;

    element.type = JSON_STR;
    element.value.str.len = strlen(value);
    element.value.str.value = strdup(value);
    if (element.value.str.value == NULL)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_array_add_element(array, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(element.value.str.value);
        }
    }
    return ret;
}

int json_array_add_str(json_array_t* array, char* value)
{
    json_array_element_t element;

    element.type = JSON_STR;
    element.value.str.len = strlen(value);
    element.value.str.value = value;
    return json_array_add_element(array, &element);
}

int json_array_add_null(json_array_t* array)
{
    json_array_element_t element;

    element.type = JSON_NULL;
    element.value.null = NULL;
    return json_array_add_element(array, &element);
}
