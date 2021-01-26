#include <stdlib.h>

#include <json/editor/destroy.h>
#include <json/internal/editor/add/object.h>
#include <json/internal/error.h>
#include <json/internal/parser/array.h>
#include <json/internal/parser/object.h>
#include <json/internal/typedef/object.h>
#include <json/internal/typedef/parser.h>
#include <json/internal/typedef/token.h>

int json_get_array_in_object(json_object_t* obj, parser_t* parser,
                             token_type_t* expected)
{
    str_t key_save = parser->key;
    json_array_t* new_array = json_parse_array(parser, expected);
    json_object_element_t element;
    int ret;

    if (json_errno != JSON_E_DEFAULT)
    {
        ret = JSON_EXIT_FAILURE;
        free(key_save.value);
    }
    else
    {
        element.key = key_save;
        element.type = JSON_ARRAY;
        element.value.array = new_array;
        parser->token.type = T_NONE;
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_array_destroy(new_array);
        }
    }
    return ret;
}

int json_get_object_in_object(json_object_t* obj, parser_t* parser,
                              token_type_t* expected)
{
    str_t key_save = parser->key;
    json_object_t* new_obj = json_parse_object(parser, expected);
    json_object_element_t element;
    int ret;

    if (json_errno != JSON_E_DEFAULT)
    {
        ret = JSON_EXIT_FAILURE;
        free(key_save.value);
    }
    else
    {
        element.key = key_save;
        element.type = JSON_OBJ;
        element.value.obj = new_obj;
        parser->token.type = T_NONE;
        ret = json_object_add_element(obj, &element);
        if (ret != JSON_EXIT_SUCCESS)
        {
            json_object_destroy(new_obj);
        }
    }
    return ret;
}
