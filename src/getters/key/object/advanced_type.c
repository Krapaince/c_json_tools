#include <json/internal/error.h>
#include <json/internal/getters/key/object.h>
#include <json/internal/typedef/array.h>

int json_object_get_object_by_key(json_object_t const* obj, char const* key,
                                  json_object_t const** value)
{
    json_object_element_t const* element;
    int ret = json_object_get_const_element_by_key_and_type(obj, key, JSON_OBJ,
                                                            &element);

    if (ret == JSON_ES)
    {
        *value = element->value.obj;
    }
    return ret;
}

int json_object_get_array_by_key(json_object_t const* obj, char const* key,
                                 json_array_t const** value)
{
    json_object_element_t const* element;
    int ret = json_object_get_const_element_by_key_and_type(
        obj, key, JSON_ARRAY, &element);

    if (ret == JSON_ES)
    {
        *value = element->value.array;
    }
    return ret;
}
