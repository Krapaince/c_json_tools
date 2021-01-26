#include <json/internal/editor/compare/type.h>
#include <json/internal/error.h>
#include <json/internal/getters/key/object.h>
#include <json/internal/typedef/object.h>

int json_object_extract_element_by_key_and_type(json_object_t* obj,
                                                char const* key,
                                                json_type_t type,
                                                json_object_element_t* element)
{
    size_t index = 0;
    int ret = json_object_get_index_by_key(obj, key, &index);
    json_object_element_t* found_elem;

    if (ret == JSON_EXIT_SUCCESS)
    {
        found_elem = &obj->elements[index];
        if (json_object_compare_element_type(found_elem, type))
        {
            *element = *found_elem;
            found_elem->type = JSON_NULL;
            found_elem->value.null = NULL;
        }
        else
        {
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}
