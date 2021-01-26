#include <stddef.h>
#include <stdlib.h>

#include <json/internal/editor/destroy/union.h>
#include <json/internal/typedef/array.h>

void json_array_destroy(json_array_t* array)
{
    size_t i = 0;

    if (array != NULL)
    {
        while (i < array->len)
        {
            json_union_value_destroy(&array->elements[i].value,
                                     array->elements[i].type);
            ++i;
        }
        free(array->elements);
        free(array);
    }
}
