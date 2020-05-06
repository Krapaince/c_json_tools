/*
** EPITECH PROJECT, 2020
** json library
** File description:
** create array
*/

#include <stdlib.h>

#include <error.h>
#include <typedef/array.h>

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
