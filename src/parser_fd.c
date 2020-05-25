/*
** EPITECH PROJECT, 2020
** json library
** File description:
** parser.c
*/

#include <error.h>
#include <parser.h>
#include <parser/array.h>
#include <parser/object.h>

// Because the function json_get_next_token doesn't know if the EOF shall be
// reach, when the EOF is encounter it's always return and error. Here is a
// catch for the invalid eof.
static void json_check_for_invalid_eof(void const* json_ptr)
{
    if (json_ptr == NULL && json_errno == JSON_E_END_OF_FILE)
    {
        json_errno = JSON_E_INVALID_EOF;
    }
}

json_object_t* json_object_parse_from_fd(int fd)
{
    parser_t parser;
    json_object_t* obj = NULL;
    token_type_t expected = T_L_BRACKET;

    json_errno_reset();
    if (json_setup_parser_from_fd(&parser, fd) == JSON_EXIT_SUCCESS)
    {
        if (json_get_next_token_object(NULL, &parser, &expected) ==
            JSON_EXIT_SUCCESS)
        {
            obj = json_parse_object(&parser, &expected);
        }
        json_check_for_invalid_eof(obj);
        json_teardown_parser_fd(&parser);
    }
    return obj;
}

json_array_t* json_array_parse_from_fd(int fd)
{
    parser_t parser;
    json_array_t* array = NULL;
    token_type_t expected = T_L_SQ_BRACKET;

    json_errno_reset();
    if (json_setup_parser_from_fd(&parser, fd) == JSON_EXIT_SUCCESS)
    {
        if (json_get_next_token_array(&parser, &expected) == JSON_EXIT_SUCCESS)
        {
            array = json_parse_array(&parser, &expected);
        }
        json_check_for_invalid_eof(array);
        json_teardown_parser_fd(&parser);
    }
    return array;
}
