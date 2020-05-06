/*
** EPITECH PROJECT, 2020
** json library
** File description:
** advanced type object
*/

#include <stdlib.h>

#include <editor/add/object.h>
#include <error.h>
#include <json/editor/destroy.h>
#include <parser/array.h>
#include <parser/object.h>
#include <typedef/object.h>
#include <typedef/parser.h>
#include <typedef/token.h>

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
