#include <stdlib.h>

#include <json/internal/editor/add/array.h>
#include <json/internal/error.h>
#include <json/internal/parser/value/str.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/token.h>

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
    if (ret == JSON_ES)
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
