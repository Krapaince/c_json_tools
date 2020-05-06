/*
** EPITECH PROJECT, 2020
** json library
** File description:
** type
*/

#include <typedef/token.h>

token_t const tokens[] = {{T_COMMA, ",", 1},        {T_L_BRACKET, "{", 1},
                          {T_R_BRACKET, "}", 1},    {T_L_SQ_BRACKET, "[", 1},
                          {T_R_SQ_BRACKET, "]", 1}, {T_COLON, ":", 1},
                          {T_BOOL_TRUE, "true", 4}, {T_BOOL_FALSE, "false", 5},
                          {T_NULL, "null", 4},      {T_ERROR, NULL, 0}};
