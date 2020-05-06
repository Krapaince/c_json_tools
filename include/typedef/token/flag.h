/*
** EPITECH PROJECT, 2020
** json library
** File description:
** token flag
*/

#ifndef JSON_TYPEDEF_TOKEN_FLAG_H_
#define JSON_TYPEDEF_TOKEN_FLAG_H_

#include <typedef/token.h>

typedef struct
{
    token_type_t type;
    void (*ptr)(token_type_t* expected);
} selector_token_flag_t;

#endif /* !JSON_TYPEDEF_TOKEN_FLAG_H_ */
