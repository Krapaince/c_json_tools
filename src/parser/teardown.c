/*
** EPITECH PROJECT, 2020
** json library
** File description:
** parser teardown.c
*/

#include <stdio.h>
#include <stdlib.h>

#include <error.h>
#include <parser.h>

static void json_teardown_parser(parser_t* parser)
{
    if (json_errno != JSON_E_DEFAULT)
    {
        free(parser->key.value);
        json_error_line = parser->line;
    }
}

static void json_teardown_parser_type_file(parser_t* parser)
{
    free(parser->source.file.buffer);
    json_teardown_parser(parser);
}

static void json_teardown_parser_type_str(parser_t* parser)
{
    json_teardown_parser(parser);
}

void json_teardown_parser_fd(parser_t* parser)
{
    json_teardown_parser_type_file(parser);
}

void json_teardown_parser_filepath(parser_t* parser)
{
    fclose(parser->source.file.fstream);
    json_teardown_parser_type_file(parser);
}

void json_teardown_parser_str(parser_t* parser)
{
    json_teardown_parser_type_str(parser);
}
