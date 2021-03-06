#include <stdlib.h>

#include <json/internal/editor/destroy/union.h>
#include <json/internal/typedef/object.h>

void json_object_destroy(json_object_t* obj)
{
    size_t i = 0;

    if (obj != NULL)
    {
        while (i < obj->len)
        {
            json_union_value_destroy(&obj->elements[i].value,
                                     obj->elements[i].type);
            free(obj->elements[i].key.value);
            ++i;
        }
        free(obj->elements);
        free(obj);
    }
}
