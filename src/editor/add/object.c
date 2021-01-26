#include <stdlib.h>

#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

static int json_object_increase_size(json_object_t* obj)
{
    int ret;
    size_t const nb_value_add = 25;
    size_t const size = obj->len_alloc + nb_value_add;
    json_object_element_t* elements =
        realloc(obj->elements, sizeof(json_object_element_t) * size);

    if (elements == NULL)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        obj->elements = elements;
        obj->len_alloc = size;
        ret = JSON_EXIT_SUCCESS;
    }
    return ret;
}

int json_object_add_element(json_object_t* obj, json_object_element_t* element)
{
    int ret = JSON_EXIT_SUCCESS;

    if (obj->len_alloc <= obj->len)
    {
        ret = json_object_increase_size(obj);
    }
    if (ret == JSON_EXIT_SUCCESS)
    {
        obj->elements[obj->len] = *element;
        ++obj->len;
    }
    return ret;
}
