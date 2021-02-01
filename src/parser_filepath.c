#include <json/editor/destroy.h>
#include <json/internal/error.h>
#include <json/internal/parser.h>
#include <json/internal/parser/array.h>
#include <json/internal/parser/object.h>

// Because the function json_get_next_token doesn't know if the EOF shall be
// reach, when the EOF is encounter it always returns an error. Here is a
// catch for the invalid eof.
static int json_does_eof_is_valid(parser_t* parser, void* json_ptr)
{
    int ret = JSON_ES;

    if (json_ptr == NULL && json_errno == JSON_E_END_OF_FILE)
    {
        json_errno = JSON_E_INVALID_EOF;
        ret = JSON_EF;
    }
    else if (json_ptr)
    {
        ret = json_parser_find_next_type(parser, T_ERROR);
        if (ret == JSON_EF && json_errno == JSON_E_END_OF_FILE)
        {
            json_errno_reset();
            ret = JSON_ES;
        }
        else
        {
            json_errno = JSON_E_INVALID_EOF;
            ret = JSON_EF;
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

    if (ret == JSON_EF)
    {
        return obj;
    }
    json_errno_reset();
    if (json_get_next_token_object(NULL, &parser, &expected) == JSON_ES)
    {
        obj = json_parse_object(&parser, &expected);
    }
    ret = json_does_eof_is_valid(&parser, obj);
    if (ret != JSON_ES && obj)
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

    if (ret == JSON_EF)
    {
        return array;
    }
    json_errno_reset();
    if (json_get_next_token_array(&parser, &expected) == JSON_ES)
    {
        array = json_parse_array(&parser, &expected);
    }
    ret = json_does_eof_is_valid(&parser, array);
    if (ret != JSON_ES && array)
    {
        json_array_destroy(array);
        array = NULL;
    }
    json_teardown_parser_filepath(&parser);
    return array;
}
