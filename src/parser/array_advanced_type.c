#include <json/editor/destroy.h>
#include <json/internal/editor/add/array.h>
#include <json/internal/error.h>
#include <json/internal/parser/array.h>
#include <json/internal/parser/object.h>
#include <json/internal/parser/value/array.h>
#include <json/internal/parser/value/object.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/object.h>
#include <json/internal/typedef/parser.h>

int json_get_array_in_array(json_array_t* array, parser_t* parser,
                            token_type_t* expected)
{
    json_array_t* sub_array = json_parse_array(parser, expected);
    json_array_element_t element;
    int ret;

    if (json_errno != JSON_E_DEFAULT)
    {
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        element.type = JSON_ARRAY;
        element.value.array = sub_array;
        parser->token.type = T_NONE;
        ret = json_array_add_element(array, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_array_destroy(sub_array);
        }
    }
    return ret;
}

int json_get_object_in_array(json_array_t* array, parser_t* parser,
                             token_type_t* expected)
{
    json_object_t* sub_object = json_parse_object(parser, expected);
    json_array_element_t element;
    int ret;

    if (json_errno != JSON_E_DEFAULT)
    {
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        element.type = JSON_OBJ;
        element.value.obj = sub_object;
        parser->token.type = T_NONE;
        ret = json_array_add_element(array, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_object_destroy(sub_object);
        }
    }
    return ret;
}
