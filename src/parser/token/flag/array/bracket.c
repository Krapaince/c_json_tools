/*
** EPITECH PROJECT, 2020
** json library
** File description:
** array bracket flag update functions
*/

#include <parser/token/flag/object.h>
#include <typedef/token.h>

void json_update_token_flag_array_l_sq_bracket(token_type_t* expected)
{
    *expected = T_TYPE | T_L_BRACKET | T_L_SQ_BRACKET | T_R_SQ_BRACKET;
}

void json_update_token_flag_array_r_sq_bracket(token_type_t* expected)
{
    *expected = T_COMMA | T_R_SQ_BRACKET;
}

void json_update_token_flag_array_l_bracket(token_type_t* expected)
{
    json_set_token_flag_obj(expected);
}

void json_update_token_flag_array_r_bracket(token_type_t* expected)
{
    *expected = T_COMMA | T_R_BRACKET;
}
