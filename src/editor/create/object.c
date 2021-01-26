#include <stdlib.h>

#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

json_object_t* json_object_create(void)
{
    json_object_t* ptr = malloc(sizeof(json_object_t));

    if (ptr)
    {
        ptr->elements = NULL;
        ptr->len = 0;
        ptr->len_alloc = 0;
    }
    else
    {
        json_errno = JSON_E_SYS_FAILURE;
    }
    return ptr;
}
