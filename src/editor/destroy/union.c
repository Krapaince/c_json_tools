#include <stdlib.h>

#include <json/editor/destroy.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/object.h>

void json_union_value_destroy(json_union_value_t* value, json_type_t type)
{
    switch (type)
    {
        case JSON_ARRAY:
            json_array_destroy(value->array);
            break;
        case JSON_OBJ:
            json_object_destroy(value->obj);
            break;
        case JSON_STR:
            free(value->str.value);
            break;
        default:
            break;
    }
}
