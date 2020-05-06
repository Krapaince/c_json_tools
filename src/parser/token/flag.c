/*
** EPITECH PROJECT, 2020
** json library
** File description:
** flag
*/

#include <error.h>
#include <typedef/token.h>

void json_set_flag_error_synthax(token_type_t* expected)
{
    *expected = T_ERROR;
    json_errno = JSON_E_SYNTHAX;
}
