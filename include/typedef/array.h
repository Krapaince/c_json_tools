/*
** EPITECH PROJECT, 2020
** json library
** File description:
** array
*/

#ifndef JSON_TYPEDEF_ARRAY_H_
#define JSON_TYPEDEF_ARRAY_H_

#include <stddef.h>

#include "type.h"

typedef struct
{
    json_type_t type;
    json_union_value_t value;
} json_array_element_t;

typedef struct json_array_s
{
    json_array_element_t* elements;
    size_t len;
    size_t len_alloc;
} json_array_t;

#endif /* !JSON_TYPEDEF_ARRAY_H_ */
