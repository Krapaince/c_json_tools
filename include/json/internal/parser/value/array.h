#ifndef JSON_INTERNAL_PARSER_VALUE_ARRAY_H_
#define JSON_INTERNAL_PARSER_VALUE_ARRAY_H_

#include <json/internal/typedef/array.h>
#include <json/internal/typedef/object.h>
#include <json/internal/typedef/token.h>

int json_parser_array_append_bool(json_array_t* array, token_t* token);
int json_parser_array_append_nb(json_array_t* array, token_t* token);
int json_parser_array_append_str(json_array_t* array, token_t* token);
int json_parser_array_append_null(json_array_t* array, token_t* token);

#endif /* !JSON_INTERNAL_PARSER_VALUE_ARRAY_H_ */
