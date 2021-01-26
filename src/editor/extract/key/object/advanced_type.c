#include <json/internal/editor/extract/key/object.h>
#include <json/internal/error.h>

int json_object_extract_object_by_key(json_object_t* obj, char const* key,
                                      json_object_t** value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_key_and_type(obj, key, JSON_OBJ,
                                                          &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.obj;
    }
    return ret;
}

int json_object_extract_array_by_key(json_object_t* obj, char const* key,
                                     json_array_t** value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_key_and_type(obj, key, JSON_ARRAY,
                                                          &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.array;
    }
    return ret;
}
