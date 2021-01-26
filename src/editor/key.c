#include <string.h>

#include <json/getters/object.h>
#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

int json_assign_key_to_element(json_object_element_t* element, char const* key)
{
    int ret;

    element->key.len = strlen(key);
    element->key.value = strdup(key);
    if (element->key.value)
    {
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_assign_key_to_element_safe(json_object_t const* obj,
                                    json_object_element_t* element,
                                    char const* key)
{
    int ret;

    if (json_object_does_key_exist(obj, key))
    {
        json_errno = JSON_E_KEY_ALREADY_EXIST;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_assign_key_to_element(element, key);
    }
    return ret;
}
