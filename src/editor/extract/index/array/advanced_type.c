#include <json/internal/editor/extract/index/array.h>
#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

int json_array_extract_object_by_index(json_array_t* array, size_t index,
                                       json_object_t** value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(array, index,
                                                           JSON_OBJ, &element);

    if (ret == JSON_ES)
    {
        *value = element.value.obj;
    }
    return ret;
}

int json_array_extract_array_by_index(json_array_t* array, size_t index,
                                      json_array_t** value)
{
    json_array_element_t element;
    int ret = json_array_extract_element_by_index_and_type(
        array, index, JSON_ARRAY, &element);

    if (ret == JSON_ES)
    {
        *value = element.value.array;
    }
    return ret;
}
