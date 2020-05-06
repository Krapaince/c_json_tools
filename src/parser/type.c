/*
** EPITECH PROJECT, 2020
** json library
** File description:
** type.c
*/

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <error.h>
#include <parser.h>
#include <typedef/parser.h>

token_t const* json_get_next_know_token(char const* str)
{
    size_t i = 0;
    token_t const* token;

    while (tokens[i].value)
    {
        token = &tokens[i];
        if (strncmp(token->value, str, token->length) == 0)
        {
            return token;
        }
        ++i;
    }
    return NULL;
}

static bool json_is_number_type(char const* token)
{
    size_t index = 0;
    bool is_negative = false;
    bool ret = true;

    if (token[0] == '-')
    {
        ++index;
        is_negative = true;
    }
    while (isdigit(token[index]))
    {
        ++index;
    }
    if (token[index] == '\0')
    {
        if (is_negative == true)
        {
            ret = 1 < index;
        }
    }
    else
    {
        ret = false;
    }
    return ret;
}

static bool json_is_string_type(token_t const* token, char quote)
{
    return (1 < token->length && token->value[0] == quote &&
            token->value[token->length - 1] == quote);
}

static int json_identify_undetermined_type(parser_t* parser,
                                           token_type_t expected)
{
    int ret = JSON_EXIT_SUCCESS;
    token_type_t type = T_ERROR;

    if (json_is_number_type(parser->token.value))
    {
        type = T_NB;
    }
    if (json_is_string_type(&parser->token, parser->quote))
    {
        if (expected & T_KEY)
        {
            type = T_KEY;
        }
        else
        {
            type = T_STR;
        }
    }
    parser->token.type = type;
    if (type == T_ERROR)
    {
        json_errno = JSON_E_UNKNOW_TYPE;
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}

int json_parser_find_next_type(parser_t* parser, token_type_t expected)
{
    parser->token.type = T_ERROR;
    parser->token.length = 0;
    free(parser->token.value);
    parser->token.value = NULL;
    if (json_parser_find_next_token(parser) == JSON_EXIT_FAILURE)
    {
        return JSON_EXIT_FAILURE;
    }
    if (parser->token.type != T_UNDETERMINED)
    {
        return JSON_EXIT_SUCCESS;
    }
    return json_identify_undetermined_type(parser, expected);
}
