#include <json/internal/getters/key/object.h>
#include <json/internal/typedef/object.h>

bool json_object_does_key_exist(json_object_t const* obj, char const* key)
{
    json_object_element_t const* element = NULL;

    json_object_get_const_element_by_key(obj, key, &element);
    return element != NULL;
}
