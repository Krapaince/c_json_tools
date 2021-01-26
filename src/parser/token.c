#include <json/internal/parser.h>
#include <json/internal/typedef/parser.h>

int json_parser_find_next_token(parser_t* parser)
{
    int ret;

    if (parser->type == PARSER_FILE)
    {
        ret = json_parser_file_find_next_token(parser);
    }
    else
    {
        ret = json_parser_str_find_next_token(parser);
    }
    return ret;
}
