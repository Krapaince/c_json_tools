#include <stdlib.h>
#include <string.h>

#include <json/getters/object.h>
#include <json/internal/editor/add/object.h>
#include <json/internal/editor/key.h>
#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

int json_object_append_bool(json_object_t* obj, char const* key, bool value)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_add_bool(obj, key, value);
    }

    return ret;
}

int json_object_append_nb(json_object_t* obj, char const* key, int value)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_add_nb(obj, key, value);
    }

    return ret;
}

int json_object_append_str_dup(json_object_t* obj, char const* key,
                               char const* value)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_add_str_dup(obj, key, value);
    }

    return ret;
}

int json_object_append_str(json_object_t* obj, char const* key, char* value)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_add_str(obj, key, value);
    }

    return ret;
}

int json_object_append_null(json_object_t* obj, char const* key)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_add_null(obj, key);
    }

    return ret;
}
