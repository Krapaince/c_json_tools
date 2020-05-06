/*
** EPITECH PROJECT, 2020
** json library
** File description:
** add basic type to an array
*/

#include <stdlib.h>

#include <editor/add/array.h>
#include <error.h>
#include <parser/value/str.h>
#include <typedef/array.h>
#include <typedef/token.h>

int json_parser_array_append_bool(json_array_t* array, token_t* token)
{
    json_array_element_t element;

    element.type = JSON_BOOL;
    element.value.boolean = token->type & (T_BOOL_TRUE ^ T_BOOL);
    return json_array_add_element(array, &element);
}

int json_parser_array_append_nb(json_array_t* array, token_t* token)
{
    json_array_element_t element;

    element.type = JSON_NB;
    element.value.nb = atoi(token->value);
    return json_array_add_element(array, &element);
}

int json_parser_array_append_str(json_array_t* array, token_t* token)
{
    json_array_element_t element;
    int ret;

    element.type = JSON_STR;
    element.value.str.value = token->value;
    element.value.str.len = token->length;
    json_remove_str_quote(&element.value.str);
    ret = json_array_add_element(array, &element);
    if (ret == JSON_EXIT_SUCCESS)
    {
        token->value = NULL;
    }
    return ret;
}

int json_parser_array_append_null(json_array_t* array, token_t* token)
{
    json_array_element_t element;

    (void)token;
    element.type = JSON_NULL;
    element.value.null = NULL;
    return json_array_add_element(array, &element);
}
