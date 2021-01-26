#include <json/internal/error.h>
#include <json/internal/getters/key/object.h>
#include <json/internal/typedef/object.h>

int json_object_get_bool_by_key(json_object_t const* obj, char const* key,
                                bool* value)
{
    json_object_element_t const* element;
    int ret = json_object_get_const_element_by_key_and_type(obj, key, JSON_BOOL,
                                                            &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.boolean;
    }
    return ret;
}

int json_object_get_nb_by_key(json_object_t const* obj, char const* key,
                              int* value)
{
    json_object_element_t const* element;
    int ret = json_object_get_const_element_by_key_and_type(obj, key, JSON_NB,
                                                            &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.nb;
    }
    return ret;
}

int json_object_get_string_by_key(json_object_t const* obj, char const* key,
                                  char const** value)
{
    json_object_element_t const* element;
    int ret = json_object_get_const_element_by_key_and_type(obj, key, JSON_STR,
                                                            &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.str.value;
    }
    return ret;
}

int json_object_get_str_by_key(json_object_t const* obj, char const* key,
                               str_t const** value)
{
    json_object_element_t const* element;
    int ret = json_object_get_const_element_by_key_and_type(obj, key, JSON_STR,
                                                            &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = &element->value.str;
    }
    return ret;
}

int json_object_get_null_by_key(json_object_t const* obj, char const* key,
                                void const** value)
{
    json_object_element_t const* element;
    int ret = json_object_get_const_element_by_key_and_type(obj, key, JSON_NULL,
                                                            &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element->value.null;
    }
    return ret;
}
