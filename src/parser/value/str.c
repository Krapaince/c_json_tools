/*
** EPITECH PROJECT, 2020
** json library
** File description:
** str
*/

#include <stddef.h>
#include <string.h>

#include <typedef/token.h>
#include <typedef/type.h>

void json_remove_str_quote(str_t* str)
{
    str->len -= 2;
    memmove(str->value, str->value + 1, str->len);
    str->value[str->len] = '\0';
}
