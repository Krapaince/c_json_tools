/*
** EPITECH PROJECT, 2020
** json library
** File description:
** token
*/

#ifndef JSON_TYPEDEF_TOKEN_H_
#define JSON_TYPEDEF_TOKEN_H_

#include <stddef.h>

typedef enum
{
    T_NONE = 0,
    T_ERROR = 1,
    T_UNDETERMINED = 1 << 1, // When a token isn't a part of know token

    T_BOOL = 1 << 2,
    T_BOOL_FALSE = T_BOOL | (1 << 3),
    T_BOOL_TRUE = T_BOOL | (1 << 4),

    T_NB = 1 << 5,
    T_STR = 1 << 6,
    T_NULL = 1 << 7,

    T_KEY = 1 << 8,

    T_COLON = 1 << 9,  // :
    T_COMMA = 1 << 10, // ,

    T_L_SQ_BRACKET = 1 << 11, // [
    T_R_SQ_BRACKET = 1 << 12, // ]
    T_L_BRACKET = 1 << 13,    // {
    T_R_BRACKET = 1 << 14,    // }

    T_TYPE = T_BOOL | T_NB | T_STR | T_NULL,
} token_type_t;

typedef struct
{
    token_type_t type;
    char* value;
    size_t length;
} token_t;

extern token_t const tokens[];

#endif /* !JSON_TYPEDEF_TOKEN_H_ */
