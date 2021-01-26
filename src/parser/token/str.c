#include <string.h>

#include <json/internal/error.h>
#include <json/internal/parser.h>
#include <json/internal/strtok.h>
#include <json/internal/typedef/parser.h>

static int json_skip_whitespaces(parser_t* parser)
{
    size_t i = parser->index;
    char const* buffer = parser->source.str.buffer;
    int ret;

    while (buffer[i] && index(parser->whitespaces, buffer[i]))
    {
        if (buffer[i] == '\n')
        {
            ++parser->line;
        }
        ++i;
    }
    if (buffer[i] == '\0')
    {
        json_errno = JSON_E_INVALID_EOF;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        parser->index = i;
        ret = JSON_EXIT_SUCCESS;
    }
    return ret;
}

static int json_identify_know_token(parser_t* parser)
{
    int ret;
    token_t const* token =
        json_get_next_know_token(&parser->source.str.buffer[parser->index]);

    if (token)
    {
        parser->token.type = token->type;
        parser->index += token->length;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        ret = json_strtok(parser->source.str.buffer, &parser->index,
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

int json_parser_str_find_next_token(parser_t* parser)
{
    int ret = json_skip_whitespaces(parser);

    if (ret == JSON_EXIT_SUCCESS)
    {
        ret = json_identify_know_token(parser);
    }
    return ret;
}
