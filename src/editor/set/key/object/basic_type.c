#include <string.h>

#include <json/internal/editor/add/object.h>
#include <json/internal/editor/destroy/union.h>
#include <json/internal/editor/key.h>
#include <json/internal/error.h>
#include <json/internal/getters/key/object.h>
#include <json/internal/typedef/object.h>

int json_object_set_bool_by_key(json_object_t* obj, char const* key, bool value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_ES)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_BOOL;
        element->value.boolean = value;
    }
    else
    {
        ret = json_object_add_bool(obj, key, value);
    }
    return ret;
}

int json_object_set_nb_by_key(json_object_t* obj, char const* key, int value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_ES)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_NB;
        element->value.nb = value;
    }
    else
    {
        ret = json_object_add_nb(obj, key, value);
    }
    return ret;
}

int json_object_set_str_dup_by_key(json_object_t* obj, char const* key,
                                   char const* value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);
    char* dup_value;

    if (ret == JSON_ES)
    {
        dup_value = strdup(value);
        if (dup_value)
        {
            json_union_value_destroy(&element->value, element->type);
            element->type = JSON_STR;
            element->value.str.value = dup_value;
            element->value.str.len = strlen(dup_value);
        }
        else
        {
            json_errno = JSON_E_SYS_FAILURE;
            ret = JSON_EF;
        }
    }
    else
    {
        ret = json_object_add_str_dup(obj, key, value);
    }
    return ret;
}

int json_object_set_str_by_key(json_object_t* obj, char const* key, char* value)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_ES)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_STR;
        element->value.str.value = value;
        element->value.str.len = strlen(value);
    }
    else
    {
        ret = json_object_add_str(obj, key, value);
    }
    return ret;
}

int json_object_set_null_by_key(json_object_t* obj, char const* key)
{
    json_object_element_t* element;
    int ret = json_object_get_element_by_key(obj, key, &element);

    if (ret == JSON_ES)
    {
        json_union_value_destroy(&element->value, element->type);
        element->type = JSON_NULL;
        element->value.null = NULL;
    }
    else
    {
        ret = json_object_add_null(obj, key);
    }
    return ret;
}
