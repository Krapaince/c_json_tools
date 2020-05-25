/*
** EPITECH PROJECT, 2020
** json library
** File description:
** parser filepath
*/

#include <error.h>
#include <json/editor/destroy.h>
#include <parser.h>
#include <parser/array.h>
#include <parser/object.h>

// Because the function json_get_next_token doesn't know if the EOF shall be
// reach, when the EOF is encounter it's always return and error. Here is a
// catch for the invalid eof.
static int json_does_eof_is_valid(parser_t* parser, void* json_ptr)
{
    int ret = JSON_EXIT_SUCCESS;

    if (json_ptr == NULL && json_errno == JSON_E_END_OF_FILE)
    {
        json_errno = JSON_E_INVALID_EOF;
        ret = JSON_EXIT_FAILURE;
    }
    else if (json_ptr)
    {
        ret = json_parser_find_next_type(parser, T_ERROR);
        if (ret == JSON_EXIT_FAILURE && json_errno == JSON_E_END_OF_FILE)
        {
            json_errno_reset();
            ret = JSON_EXIT_SUCCESS;
        }
        else
        {
            json_errno = JSON_E_INVALID_EOF;
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}

json_object_t* json_object_parse_from_filepath(char const* filepath)
{
    parser_t parser;
    json_object_t* obj = NULL;
    token_type_t expected = T_L_BRACKET;
    int ret = json_setup_parser_from_filepath(&parser, filepath);

    if (ret == JSON_EXIT_FAILURE)
    {
        return obj;
    }
    json_errno_reset();
    if (json_get_next_token_object(NULL, &parser, &expected) ==
        JSON_EXIT_SUCCESS)
    {
        obj = json_parse_object(&parser, &expected);
    }
    ret = json_does_eof_is_valid(&parser, obj);
    if (ret != JSON_EXIT_SUCCESS && obj)
    {
        json_object_destroy(obj);
        obj = NULL;
    }
    json_teardown_parser_filepath(&parser);
    return obj;
}

json_array_t* json_array_parse_from_filepath(char const* filepath)
{
    parser_t parser;
    json_array_t* array = NULL;
    token_type_t expected = T_L_SQ_BRACKET;
    int ret = json_setup_parser_from_filepath(&parser, filepath);

    if (ret == JSON_EXIT_FAILURE)
    {
        return array;
    }
    json_errno_reset();
    if (json_get_next_token_array(&parser, &expected) == JSON_EXIT_SUCCESS)
    {
        array = json_parse_array(&parser, &expected);
    }
    ret = json_does_eof_is_valid(&parser, array);
    if (ret != JSON_EXIT_SUCCESS && array)
    {
        json_array_destroy(array);
        array = NULL;
    }
    json_teardown_parser_filepath(&parser);
    return array;
}
