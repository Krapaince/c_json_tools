#include <stdio.h>
#include <stdlib.h>

#include <json/internal/error.h>
#include <json/internal/typedef/parser.h>

static void json_init_parser(parser_t* parser, parser_type_t type)
{
    if (type == PARSER_FILE)
    {
        parser->source.file.buffer = NULL;
        parser->source.file.buffer_size = 0;
    }
    parser->type = type;
    parser->line = 0;
    parser->index = 0;
    parser->key.len = 0;
    parser->key.value = NULL;
    parser->token.type = T_ERROR;
    parser->token.value = NULL;
    parser->token.length = 0;
    parser->whitespaces = WHITESPACES;
    parser->delimiters = WHITESPACES STRUCTURAL_TOKENS;
    parser->quote = '"';
    json_errno_reset();
}

int json_setup_parser_from_fd(parser_t* parser, int fd)
{
    int ret = JSON_EXIT_SUCCESS;

    parser->source.file.fstream = fdopen(fd, "r");
    if (parser->source.file.fstream == NULL)
    {
        ret = JSON_EXIT_FAILURE;
        json_errno = JSON_E_SYS_FAILURE;
    }
    else
    {
        json_init_parser(parser, PARSER_FILE);
    }
    return ret;
}

int json_setup_parser_from_filepath(parser_t* parser, char const* filepath)
{
    int ret = JSON_EXIT_SUCCESS;

    parser->source.file.fstream = fopen(filepath, "r");
    if (parser->source.file.fstream == NULL)
    {
        ret = JSON_EXIT_FAILURE;
        json_errno = JSON_E_SYS_FAILURE;
    }
    else
    {
        json_init_parser(parser, PARSER_FILE);
    }
    return ret;
}

void json_setup_parser_from_str(parser_t* parser, char const* str)
{
    json_init_parser(parser, PARSER_STRING);
    parser->source.str.buffer = str;
}
