#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <json/internal/error.h>
#include <json/internal/parser.h>
#include <json/internal/strtok.h>
#include <json/internal/typedef/parser.h>

static int json_get_next_lign(parser_t* parser)
{
    int ret = JSON_EXIT_SUCCESS;
    ssize_t nbytes;
    parser_file_t* file = &parser->source.file;

    errno = 0;
    nbytes = getline(&file->buffer, &file->buffer_size, file->fstream);
    parser->index = 0;
    ++parser->line;
    if (nbytes == -1)
    {
        ret = JSON_EXIT_FAILURE;
        if (errno != 0)
        {
            json_errno = JSON_E_SYS_FAILURE;
        }
        else
        {
            json_errno = JSON_E_END_OF_FILE;
        }
        free(parser->source.file.buffer);
        parser->source.file.buffer = NULL;
        parser->source.file.buffer_size = 0;
    }
    return ret;
}

static void json_skip_whitespaces(parser_t* parser)
{
    size_t i = parser->index;
    char const* buffer = parser->source.file.buffer;

    if (buffer)
    {
        while (buffer[i] && index(parser->whitespaces, buffer[i]))
        {
            ++i;
        }
        parser->index = i;
    }
}

static int json_identify_know_token(parser_t* parser)
{
    int ret;
    token_t const* token =
        json_get_next_know_token(&parser->source.file.buffer[parser->index]);

    if (token)
    {
        parser->token.type = token->type;
        parser->index += token->length;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = json_strtok(parser->source.file.buffer, &parser->index,
                          parser->delimiters, parser->quote,
                          &parser->token.value);
        if (ret == JSON_EXIT_SUCCESS)
        {
            parser->token.length = strlen(parser->token.value);
            parser->token.type = T_UNDETERMINED;
        }
    }
    return ret;
}

int json_parser_file_find_next_token(parser_t* parser)
{
    int ret;

    json_skip_whitespaces(parser);
    if (parser->source.file.buffer == NULL ||
        parser->source.file.buffer[parser->index] == '\0')
    {
        if (json_get_next_lign(parser) == JSON_EXIT_FAILURE)
        {
            ret = JSON_EXIT_FAILURE;
        }
        else
        {
            ret = json_parser_file_find_next_token(parser);
        }
    }
    else
    {
        ret = json_identify_know_token(parser);
    }
    return ret;
}
