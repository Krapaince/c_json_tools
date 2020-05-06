/*
** EPITECH PROJECT, 2020
** json library
** File description:
** obj bracket flag update functions
*/

#include <parser/token/flag/array.h>
#include <typedef/token.h>

void json_update_token_flag_obj_l_sq_bracket(token_type_t* expected)
{
    json_set_token_flag_array(expected);
}

void json_update_token_flag_obj_r_sq_bracket(token_type_t* expected)
{
    *expected = T_COMMA | T_R_BRACKET;
}

void json_update_token_flag_obj_l_bracket(token_type_t* expected)
{
    *expected = T_KEY | T_R_BRACKET;
}

void json_update_token_flag_obj_r_bracket(token_type_t* expected)
{
    *expected = T_COMMA | T_R_BRACKET;
}
