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

static void json_parse_update_index(size_t* index, size_t parser_index)
{
    if (index != NULL)
    {
        *index = parser_index;
    }
}

json_object_t* json_object_parse_from_str(char const* str, size_t* index)
{
    parser_t parser;
    json_object_t* obj = NULL;
    token_type_t expected = T_L_BRACKET;

    json_setup_parser_from_str(&parser, str);
    if (json_get_next_token_object(NULL, &parser, &expected) ==
        JSON_EXIT_SUCCESS)
    {
        obj = json_parse_object(&parser, &expected);
        if (obj)
        {
            json_parse_update_index(index, parser.index);
        }
    }
    json_teardown_parser_str(&parser);
    return obj;
}

json_array_t* json_array_parse_from_str(char const* str, size_t* index)
{
    parser_t parser;
    json_array_t* array = NULL;
    token_type_t expected = T_L_SQ_BRACKET;

    json_setup_parser_from_str(&parser, str);
    if (json_get_next_token_array(&parser, &expected) == JSON_EXIT_SUCCESS)
    {
        array = json_parse_array(&parser, &expected);
        if (array)
        {
            json_parse_update_index(index, parser.index);
        }
    }
    json_teardown_parser_str(&parser);
    return array;
}
