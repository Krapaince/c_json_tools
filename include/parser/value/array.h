/*
** EPITECH PROJECT, 2020
** json library
** File description:
** parser value array
*/

#ifndef JSON_PARSER_VALUE_ARRAY_H_
#define JSON_PARSER_VALUE_ARRAY_H_

#include <typedef/array.h>
#include <typedef/object.h>
#include <typedef/token.h>

int json_parser_array_append_bool(json_array_t* array, token_t* token);
int json_parser_array_append_nb(json_array_t* array, token_t* token);
int json_parser_array_append_str(json_array_t* array, token_t* token);
int json_parser_array_append_null(json_array_t* array, token_t* token);

#endif /* !JSON_PARSER_VALUE_ARRAY_H_ */
