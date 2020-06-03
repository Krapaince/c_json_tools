/*
** EPITECH PROJECT, 2020
** json library
** File description:
** write token
*/

#include <stddef.h>

#include <error.h>
#include <generator/write.h>
#include <typedef/token.h>

int json_generate_type(generator_t* generator, token_type_t type)
{
    size_t i = 0;

    while (tokens[i].value != NULL)
    {
        if (tokens[i].type == type)
        {
            return json_generate_to_buffer(generator, tokens[i].value,
                                           tokens[i].length);
        }
        ++i;
    }
    json_errno = JSON_E_UNKNOW_TYPE;
    return JSON_EXIT_FAILURE;
}
