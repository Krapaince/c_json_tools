/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor create object
*/

#include <stdlib.h>

#include <error.h>
#include <typedef/object.h>

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
