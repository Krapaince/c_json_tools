#include <json/internal/editor/add/object.h>
#include <json/internal/editor/destroy/union.h>
#include <json/internal/editor/key.h>
#include <json/internal/error.h>
#include <json/internal/getters/key/object.h>
#include <json/internal/typedef/object.h>

int json_object_set_object_by_key(json_object_t* obj, char const* key,
                                  json_object_t* value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_ES)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_OBJ;
        element->value.obj = value;
    }
    else
    {
        ret = json_object_add_object(obj, key, value);
    }
    return ret;
}

int json_object_set_array_by_key(json_object_t* obj, char const* key,
                                 json_array_t* value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_ES)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_ARRAY;
        element->value.array = value;
    }
    else
    {
        ret = json_object_add_array(obj, key, value);
    }
    return ret;
}
