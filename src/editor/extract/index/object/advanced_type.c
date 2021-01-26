#include <json/internal/editor/extract/index/object.h>
#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

int json_object_extract_object_by_index(json_object_t* object, size_t index,
                                        json_object_t** value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_index_and_type(object, index,
                                                            JSON_OBJ, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.obj;
    }
    return ret;
}

int json_object_extract_array_by_index(json_object_t* object, size_t index,
                                       json_array_t** value)
{
    json_object_element_t element;
    int ret = json_object_extract_element_by_index_and_type(
        object, index, JSON_ARRAY, &element);

    if (ret == JSON_EXIT_SUCCESS)
    {
        *value = element.value.array;
    }
    return ret;
}
