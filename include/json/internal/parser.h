#ifndef JSON_INTERNAL_PARSER_H_
#define JSON_INTERNAL_PARSER_H_

#include <json/internal/typedef/object.h>
#include <json/internal/typedef/parser.h>

int json_setup_parser_from_fd(parser_t* parser, int fd);
int json_setup_parser_from_filepath(parser_t* parser, char const* filepath);
void json_setup_parser_from_str(parser_t* parser, char const* str);

void json_teardown_parser_fd(parser_t* parser);
void json_teardown_parser_filepath(parser_t* parser);
void json_teardown_parser_str(parser_t* parser);

token_t const* json_get_next_know_token(char const* str);

int json_parser_str_find_next_token(parser_t* parser);
int json_parser_file_find_next_token(parser_t* parser);

// Parses the current file to found the next token.
// If the token is part of the know token, nothing will be allocated.
// Else the token value is return and it have to be identify
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_parser_find_next_token(parser_t* parser);

// Calls json_find_next_token and if the token type is undetermined,
// json_find_next_type identify the token by parsing the token value
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_parser_find_next_type(parser_t* parser, token_type_t expected);

#endif /* !JSON_INTERNAL_PARSER_H_ */
