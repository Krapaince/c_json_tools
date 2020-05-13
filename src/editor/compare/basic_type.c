/*
** EPITECH PROJECT, 2020
** json library
** File description:
** compare basic type
*/

#include <stdbool.h>
#include <string.h>

#include <typedef/type.h>

bool json_compare_bool(bool first, bool second)
{
    return first == second;
}

bool json_compare_nb(int first, int second)
{
    return first == second;
}

bool json_compare_str(str_t const* first, str_t const* second)
{
    int ret =
        first->len == second->len && strcmp(first->value, second->value) == 0;

    return ret;
}

bool json_compare_null(void const* first, void const* second)
{
    (void)first;
    (void)second;
    return true;
}
