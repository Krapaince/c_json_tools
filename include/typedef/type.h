/*
** EPITECH PROJECT, 2020
** json library
** File description:
** type
*/

#ifndef JSON_TYPEDEF_TYPE_H_
#define JSON_TYPEDEF_TYPE_H_

#include <stdbool.h>
#include <stddef.h>

// Forward declaration
typedef struct json_object_s json_object_t;
typedef struct json_array_s json_array_t;

typedef enum
{
    JSON_BOOL,
    JSON_NB,
    JSON_STR,
    JSON_NULL,
    JSON_ARRAY,
    JSON_OBJ,
} json_type_t;

typedef struct
{
    char* value;
    size_t len;
} str_t;

typedef union
{
    bool boolean;
    int nb;
    str_t str;
    json_object_t* obj;
    json_array_t* array;
    void* null;
} json_union_value_t;

#endif /* !JSON_TYPEDEF_TYPE_H_ */
