#include <string.h>

#include <json/internal/editor/destroy/union.h>
#include <json/internal/error.h>
#include <json/internal/getters/key/object.h>
#include <json/internal/typedef/object.h>

int json_object_unset_element_by_key(json_object_t* obj, char const* key)
{
    size_t index;
    json_object_element_t* element;

    if (json_object_get_index_by_key(obj, key, &index) == JSON_EXIT_FAILURE)
    {
        return 0;
    }
    element = &obj->elements[index];
    json_union_value_destroy(&element->value, element->type);
    memmove(&obj->elements[index], &obj->elements[index + 1], obj->len - index);
    --obj->len;
    return 1;
}
