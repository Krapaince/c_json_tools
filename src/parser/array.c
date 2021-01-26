#include <json/editor/create.h>
#include <json/editor/destroy.h>
#include <json/internal/error.h>
#include <json/internal/parser.h>
#include <json/internal/parser/array.h>
#include <json/internal/parser/token/flag/array.h>
#include <json/internal/parser/value/array.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/parser.h>
#include <json/internal/typedef/token.h>

int json_get_next_token_array(parser_t* parser, token_type_t* expected)
{
    int ret = json_parser_find_next_type(parser, *expected);

    if (ret != JSON_EXIT_SUCCESS)
    {
        return ret;
    }
    return json_update_token_flag_array(parser->token.type, expected);
}

static int json_add_type_array(json_array_t* array, parser_t* parser)
{
    size_t i = 0;
    int ret = JSON_EXIT_SUCCESS;
    token_type_t const types[] = {T_BOOL, T_NB, T_STR, T_NULL, T_ERROR};
    int (*const fct_ptr[])(json_array_t * obj, token_t * token) = {
        json_parser_array_append_bool, json_parser_array_append_nb,
        json_parser_array_append_str, json_parser_array_append_null, NULL};

    while (types[i] != T_ERROR)
    {
        if (parser->token.type & types[i])
        {
            ret = fct_ptr[i](array, &parser->token);
            break;
        }
        ++i;
    }
    return ret;
}

static int json_treat_token_array(json_array_t* array, parser_t* parser,
                                  token_type_t* expected)
{
    int ret = JSON_EXIT_SUCCESS;

    if (parser->token.type & T_TYPE)
    {
        ret = json_add_type_array(array, parser);
    }
    else
    {
        switch (parser->token.type)
        {
            case T_L_BRACKET:
                ret = json_get_object_in_array(array, parser, expected);
                json_set_token_flag_array_after_element(expected);
                break;
            case T_L_SQ_BRACKET:
                ret = json_get_array_in_array(array, parser, expected);
                json_set_token_flag_array_after_element(expected);
                break;
            default:
                break;
        }
    }
    return ret;
}

json_array_t* json_parse_array(parser_t* parser, token_type_t* expected)
{
    json_array_t* array = json_array_create();
    int ret;

    if (array == NULL)
    {
        return array;
    }
    while (parser->token.type != T_R_SQ_BRACKET && json_errno == JSON_E_DEFAULT)
    {
        ret = json_get_next_token_array(parser, expected);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_array_destroy(array);
            return NULL;
        }
        ret = json_treat_token_array(array, parser, expected);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_array_destroy(array);
            return NULL;
        }
    }
    return array;
}
