/*
** EPITECH PROJECT, 2020
** json library
** File description:
** add advanced type
*/

#include <string.h>

#include <editor/add/array.h>
#include <typedef/array.h>

int json_array_append_array(json_array_t* array, json_array_t* value)
{
    return json_array_add_array(array, value);
}

int json_array_append_object(json_array_t* array, json_object_t* value)
{
    return json_array_add_object(array, value);
}
