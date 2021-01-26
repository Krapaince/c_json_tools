#ifndef JSON_INTERNAL_PARSER_VALUE_OBJECT_H_
#define JSON_INTERNAL_PARSER_VALUE_OBJECT_H_

#include <json/internal/typedef/object.h>
#include <json/internal/typedef/token.h>
#include <json/internal/typedef/type.h>

int json_parser_object_append_bool(json_object_t* obj, str_t* key,
                                   token_t* token);
int json_parser_object_append_nb(json_object_t* obj, str_t* key,
                                 token_t* token);
int json_parser_object_append_str(json_object_t* obj, str_t* key,
                                  token_t* token);
int json_parser_object_append_null(json_object_t* obj, str_t* key,
                                   token_t* token);

#endif /* !JSON_INTERNAL_PARSER_VALUE_OBJECT_H_ */
