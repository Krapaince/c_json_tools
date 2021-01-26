#include <json/editor/create.h>
#include <json/editor/destroy.h>
#include <json/internal/error.h>
#include <json/internal/parser.h>
#include <json/internal/parser/object.h>
#include <json/internal/parser/token/flag/object.h>
#include <json/internal/parser/value/object.h>
#include <json/internal/parser/value/str.h>

int json_get_next_token_object(json_object_t const* obj, parser_t* parser,
                               token_type_t* expected)
{
    int ret = json_parser_find_next_type(parser, *expected);

    if (ret != JSON_EXIT_SUCCESS)
    {
        return ret;
    }
    ret = json_update_token_flag_obj(parser->token.type, expected);
    if (ret != JSON_EXIT_SUCCESS)
    {
        return ret;
    }
    if (parser->token.type & T_KEY)
    {
        ret = json_does_key_already_exist(obj, &parser->token);
    }
    return ret;
}

static int json_add_type_object(json_object_t* obj, parser_t* parser)
{
    size_t i = 0;
    int ret = JSON_EXIT_SUCCESS;
    token_type_t const types[] = {T_BOOL, T_NB, T_STR, T_NULL, T_ERROR};
    int (*const fct_ptr[])(json_object_t * obj, str_t * key,
                           token_t * token) = {
        json_parser_object_append_bool, json_parser_object_append_nb,
        json_parser_object_append_str, json_parser_object_append_null, NULL};

    while (types[i] != T_ERROR)
    {
        if (parser->token.type & types[i])
        {
            ret = fct_ptr[i](obj, &parser->key, &parser->token);
            break;
        }
        ++i;
    }
    if (ret == JSON_EXIT_SUCCESS)
    {
        parser->key.value = NULL;
    }
    return ret;
}

static void json_treat_key_object(parser_t* parser)
{
    parser->key.value = parser->token.value;
    parser->key.len = parser->token.length;
    json_remove_str_quote(&parser->key);
    parser->token.value = NULL;
}

static int json_treat_token_object(json_object_t* obj, parser_t* parser,
                                   token_type_t* expected)
{
    int ret = JSON_EXIT_SUCCESS;

    if (parser->token.type & T_TYPE)
    {
        ret = json_add_type_object(obj, parser);
    }
    switch (parser->token.type)
    {
        case T_L_BRACKET:
            ret = json_get_object_in_object(obj, parser, expected);
            json_set_token_flag_obj_after_element(expected);
            break;
        case T_L_SQ_BRACKET:
            ret = json_get_array_in_object(obj, parser, expected);
            json_set_token_flag_obj_after_element(expected);
            break;
        case T_KEY:
            json_treat_key_object(parser);
            break;
        default:
            break;
    }
    return ret;
}

json_object_t* json_parse_object(parser_t* parser, token_type_t* expected)
{
    json_object_t* obj = json_object_create();
    int ret;

    if (obj == NULL)
    {
        return obj;
    }
    while (parser->token.type != T_R_BRACKET && json_errno == JSON_E_DEFAULT)
    {
        ret = json_get_next_token_object(obj, parser, expected);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_object_destroy(obj);
            return NULL;
        }
        ret = json_treat_token_object(obj, parser, expected);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_object_destroy(obj);
            return NULL;
        }
    }
    return obj;
}
