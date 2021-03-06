#include <string.h>

#include <json/internal/editor/compare/type.h>
#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

int json_object_get_index_by_key(json_object_t const* obj, char const* key,
                                 size_t* index)
{
    size_t i = 0;

    while (i < obj->len)
    {
        if (strcmp(obj->elements[i].key.value, key) == 0)
        {
            *index = i;
            return JSON_ES;
        }
        ++i;
    }
    return JSON_EF;
}

int json_object_get_const_element_by_key(json_object_t const* obj,
                                         char const* key,
                                         json_object_element_t const** value)
{
    size_t index;
    int ret = json_object_get_index_by_key(obj, key, &index);

    if (ret == JSON_ES)
    {
        *value = &obj->elements[index];
    }
    else
    {
        *value = NULL;
    }
    return ret;
}

int json_object_get_const_element_by_key_and_type(
    json_object_t const* obj, char const* key, json_type_t type,
    json_object_element_t const** value)
{
    int ret = json_object_get_const_element_by_key(obj, key, value);

    if (ret == JSON_ES)
    {
        if (json_object_compare_element_type(*value, type) == false)
        {
            *value = NULL;
            ret = JSON_EF;
        }
    }
    return ret;
}

int json_object_get_element_by_key(json_object_t* obj, char const* key,
                                   json_object_element_t** value)
{
    size_t index;
    int ret = json_object_get_index_by_key(obj, key, &index);

    if (ret == JSON_ES)
    {
        *value = &obj->elements[index];
    }
    else
    {
        *value = NULL;
    }
    return ret;
}

int json_object_get_element_by_key_and_type(json_object_t* obj, char const* key,
                                            json_type_t type,
                                            json_object_element_t** value)
{
    int ret = json_object_get_element_by_key(obj, key, value);

    if (ret == JSON_ES)
    {
        if (json_object_compare_element_type(*value, type) == false)
        {
            *value = NULL;
            ret = JSON_EF;
        }
    }
    return ret;
}
