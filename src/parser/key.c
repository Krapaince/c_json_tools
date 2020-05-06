/*
** EPITECH PROJECT, 2020
** json library
** File description:
** key name.c
*/

#include <stddef.h>
#include <string.h>

#include <error.h>
#include <typedef/object.h>
#include <typedef/token.h>

int json_does_key_already_exist(json_object_t const* obj, token_t const* token)
{
    size_t i = 0;
    str_t const* key;

    while (i < obj->len)
    {
        key = &obj->elements[i].key;
        if (key->len == token->length - 2 &&
            strncmp(&token->value[1], key->value, key->len) == 0)
        {
            json_errno = JSON_E_KEY_DUPLICATED;
            return JSON_EXIT_FAILURE;
        }
        ++i;
    }
    return JSON_EXIT_SUCCESS;
}
