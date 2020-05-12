/*
** EPITECH PROJECT, 2020
** json library
** File description:
** parser str
*/

#include <error.h>
#include <json/editor/destroy.h>
#include <parser.h>
#include <parser/array.h>
#include <parser/object.h>

static int json_does_eof_is_valid(parser_t* parser)
{
    int ret = json_parser_find_next_type(parser, T_ERROR);

    if (ret != JSON_EXIT_SUCCESS && json_errno == JSON_E_INVALID_EOF)
    {
        ret = JSON_EXIT_SUCCESS;
        json_errno_reset();
    }
    else
    {
        ret = JSON_EXIT_FAILURE;
        json_errno = JSON_E_INVALID_EOF;
    }
    return ret;
}

json_object_t* json_object_parse_from_str(char const* str)
{
    parser_t parser;
    json_object_t* obj = NULL;
    token_type_t expected = T_L_BRACKET;

    json_setup_parser_from_str(&parser, str);
    if (json_get_next_token_object(NULL, &parser, &expected) ==
        JSON_EXIT_SUCCESS)
    {
        obj = json_parse_object(&parser, &expected);
    }
    if (obj && json_does_eof_is_valid(&parser) != JSON_EXIT_SUCCESS)
    {
        json_object_destroy(obj);
        obj = NULL;
    }
    json_teardown_parser_str(&parser);
    return obj;
}

json_array_t* json_array_parse_from_str(char const* str)
{
    parser_t parser;
    json_array_t* array = NULL;
    token_type_t expected = T_L_SQ_BRACKET;

    json_setup_parser_from_str(&parser, str);
    if (json_get_next_token_array(&parser, &expected) == JSON_EXIT_SUCCESS)
    {
        array = json_parse_array(&parser, &expected);
    }
    if (array && json_does_eof_is_valid(&parser) != JSON_EXIT_SUCCESS)
    {
        json_array_destroy(array);
        array = NULL;
    }
    json_teardown_parser_str(&parser);
    return array;
}
