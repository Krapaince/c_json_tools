#include <json/internal/error.h>
#include <json/internal/getters/index/object.h>
#include <json/internal/typedef/object.h>

int json_object_get_bool_by_index(json_object_t const* object, size_t index,
                                  bool* value)
{
    json_object_element_t const* element = NULL;
    int ret = json_object_get_const_element_by_index_and_type(
        object, index, JSON_BOOL, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.boolean;
    }
    return ret;
}

int json_object_get_nb_by_index(json_object_t const* object, size_t index,
                                int* value)
{
    json_object_element_t const* element = NULL;
    int ret = json_object_get_const_element_by_index_and_type(
        object, index, JSON_NB, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.nb;
    }
    return ret;
}

int json_object_get_str_by_index(json_object_t const* object, size_t index,
                                 str_t const** value)
{
    json_object_element_t const* element = NULL;
    int ret = json_object_get_const_element_by_index_and_type(
        object, index, JSON_STR, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = &element->value.str;
    }
    return ret;
}

int json_object_get_null_by_index(json_object_t const* object, size_t index,
                                  void const** value)
{
    json_object_element_t const* element = NULL;
    int ret = json_object_get_const_element_by_index_and_type(
        object, index, JSON_NULL, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.null;
    }
    return ret;
}
