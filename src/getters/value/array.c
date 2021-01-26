#include <json/internal/editor/compare.h>
#include <json/internal/editor/compare/type.h>
#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

static int json_array_get_index_by_value(json_array_t const* array,
                                         json_array_element_t const* element,
                                         size_t* index)
{
    size_t i = 0;
    json_array_element_t const* current;

    while (i < array->len)
    {
        current = &array->elements[i];
        if (json_compare_element(&current->value, current->type,
                                 &element->value, element->type))
        {
            *index = i;
            return JSON_EXIT_SUCCESS;
        }
        ++i;
    }
    return JSON_EXIT_FAILURE;
}

int json_array_get_index_by_value_and_type(json_array_t const* array,
                                           json_array_element_t const* element,
                                           size_t* index)
{
    int ret = json_array_get_index_by_value(array, element, index);

    if (ret == JSON_EXIT_SUCCESS)
    {
        if (json_array_compare_element_type(&array->elements[*index],
                                            element->type) == false)
        {
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}
