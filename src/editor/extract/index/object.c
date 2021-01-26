#include <json/internal/editor/compare/type.h>
#include <json/internal/error.h>
#include <json/internal/getters/index/object.h>
#include <json/internal/typedef/object.h>

int json_object_extract_element_by_index_and_type(
    json_object_t* object, size_t index, json_type_t type,
    json_object_element_t* element)
{
    json_object_element_t* found_elem = NULL;
    int ret = json_object_get_element_by_index(object, index, &found_elem);

    if (ret == JSON_ES)
    {
        if (json_object_compare_element_type(found_elem, type))
        {
            element->type = found_elem->type;
            element->value = found_elem->value;
            found_elem->type = JSON_NULL;
            found_elem->value.null = NULL;
        }
        else
        {
            ret = JSON_EF;
        }
    }
    return ret;
}
