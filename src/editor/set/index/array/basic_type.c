#include <string.h>

#include <json/internal/editor/destroy/union.h>
#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

int json_array_set_bool_by_index(json_array_t* array, size_t index, bool value)
{
    int ret;
    json_array_element_t* element;

    if (index < array->len)
    {
        element = &array->elements[index];
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_BOOL;
        element->value.boolean = value;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_array_set_nb_by_index(json_array_t* array, size_t index, int value)
{
    int ret;
    json_array_element_t* element;

    if (index < array->len)
    {
        element = &array->elements[index];
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_NB;
        element->value.nb = value;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_array_set_str_dup_by_index(json_array_t* array, size_t index,
                                    char const* value)
{
    int ret = JSON_EXIT_FAILURE;
    json_array_element_t* element;
    json_array_element_t new_elemnent;

    if (index < array->len)
    {
        new_elemnent.value.str.value = strdup(value);
        if (new_elemnent.value.str.value)
        {
            new_elemnent.type = JSON_STR;
            new_elemnent.value.str.len = strlen(value);
            element = &array->elements[index];
            json_union_value_destroy(&element->value, element->type);
            *element = new_elemnent;
            ret = JSON_EXIT_SUCCESS;
        }
        else
        {
            json_errno = JSON_E_SYS_FAILURE;
        }
    }
    return ret;
}

int json_array_set_str_by_index(json_array_t* array, size_t index, char* value)
{
    int ret;
    json_array_element_t* element;

    if (index < array->len)
    {
        element = &array->elements[index];
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_STR;
        element->value.str.value = value;
        element->value.str.len = strlen(value);
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_array_set_null_by_index(json_array_t* array, size_t index)
{
    int ret;
    json_array_element_t* element;

    if (index < array->len)
    {
        element = &array->elements[index];
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_NULL;
        element->value.null = NULL;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}
