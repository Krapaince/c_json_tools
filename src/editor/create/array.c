#include <stdlib.h>

#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

json_array_t* json_array_create(void)
{
    json_array_t* array = malloc(sizeof(json_array_t));

    if (array)
    {
        array->len = 0;
        array->len_alloc = 0;
        array->elements = NULL;
    }
    else
    {
        json_errno = JSON_E_SYS_FAILURE;
    }
    return array;
}
