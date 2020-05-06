/*
** EPITECH PROJECT, 2020
** json library
** File description:
** object flag update function
*/

#include <stdbool.h>
#include <stddef.h>

#include <error.h>
#include <parser/token/flag.h>
#include <parser/token/flag/object.h>
#include <typedef/token.h>
#include <typedef/token/flag.h>

static selector_token_flag_t const obj_flags[] = {
    {T_L_SQ_BRACKET, json_update_token_flag_obj_l_sq_bracket},
    {T_R_SQ_BRACKET, json_update_token_flag_obj_r_sq_bracket},
    {T_KEY, json_update_token_flag_obj_key},
    {T_L_BRACKET, json_update_token_flag_obj_l_bracket},
    {T_R_BRACKET, json_update_token_flag_obj_r_bracket},
    {T_COLON, json_update_token_flag_obj_colon},
    {T_COMMA, json_update_token_flag_obj_comma},
    {T_BOOL | T_NB | T_STR | T_NULL, json_update_token_flag_obj_type},
    {T_ERROR, NULL}};

void json_set_token_flag_obj(token_type_t* expected)
{
    json_update_token_flag_obj_l_bracket(expected);
}

void json_set_token_flag_obj_after_element(token_type_t* expected)
{
    *expected = T_COMMA | T_R_BRACKET;
}

int json_update_token_flag_obj(token_type_t type, token_type_t* expected)
{
    size_t i = 0;

    if (!(*expected & type))
    {
        json_set_flag_error_synthax(expected);
        return JSON_EXIT_FAILURE;
    }
    while (obj_flags[i].ptr)
    {
        if (obj_flags[i].type & type)
        {
            obj_flags[i].ptr(expected);
            return JSON_EXIT_SUCCESS;
        }
        ++i;
    }
    json_set_flag_error_synthax(expected);
    return JSON_EXIT_FAILURE;
}
