#include <stdlib.h>

#include <json/internal/editor/add/object.h>
#include <json/internal/error.h>
#include <json/internal/parser/value/str.h>
#include <json/internal/typedef/object.h>
#include <json/internal/typedef/token.h>

int json_parser_object_append_bool(json_object_t* obj, str_t* key,
                                   token_t* token)
{
    json_object_element_t element;

    element.key = *key;
    element.type = JSON_BOOL;
    element.value.boolean = token->type & (T_BOOL_TRUE ^ T_BOOL);
    return json_object_add_element(obj, &element);
}

int json_parser_object_append_nb(json_object_t* obj, str_t* key, token_t* token)
{
    json_object_element_t element;

    element.key = *key;
    element.type = JSON_NB;
    element.value.nb = atoi(token->value);
    return json_object_add_element(obj, &element);
}

int json_parser_object_append_str(json_object_t* obj, str_t* key,
                                  token_t* token)
{
    json_object_element_t element;
    int ret;

    element.key = *key;
    element.type = JSON_STR;
    element.value.str.value = token->value;
    element.value.str.len = token->length;
    json_remove_str_quote(&element.value.str);
    ret = json_object_add_element(obj, &element);
    if (ret == JSON_EXIT_SUCCESS)
    {
        token->value = NULL;
    }
    return ret;
}

int json_parser_object_append_null(json_object_t* obj, str_t* key,
                                   token_t* token)
{
    json_object_element_t element;

    (void)token;
    element.key = *key;
    element.type = JSON_NULL;
    element.value.null = NULL;
    return json_object_add_element(obj, &element);
}
