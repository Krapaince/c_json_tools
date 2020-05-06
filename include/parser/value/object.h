/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json parser value object
*/

#ifndef JSON_PARSER_VALUE_OBJECT_H_
#define JSON_PARSER_VALUE_OBJECT_H_

#include <typedef/object.h>
#include <typedef/token.h>
#include <typedef/type.h>

int json_parser_object_append_bool(json_object_t* obj, str_t* key,
                                   token_t* token);
int json_parser_object_append_nb(json_object_t* obj, str_t* key,
                                 token_t* token);
int json_parser_object_append_str(json_object_t* obj, str_t* key,
                                  token_t* token);
int json_parser_object_append_null(json_object_t* obj, str_t* key,
                                   token_t* token);

#endif /* !JSON_PARSER_VALUE_OBJECT_H_ */
