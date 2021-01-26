#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

static int json_object_get_const_element_by_index(
    json_object_t const* object, size_t index,
    json_object_element_t const** element)
{
    int ret;

    if (index < object->len)
    {
        *element = &object->elements[index];
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        *element = NULL;
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_object_get_const_element_by_index_and_type(
    json_object_t const* object, size_t index, json_type_t type,
    json_object_element_t const** element)
{
    int ret = json_object_get_const_element_by_index(object, index, element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        if ((*element)->type != type)
        {
            *element = NULL;
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}

int json_object_get_element_by_index(json_object_t* object, size_t index,
                                     json_object_element_t** element)
{
    int ret;

    if (index < object->len)
    {
        *element = &object->elements[index];
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        *element = NULL;
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}
