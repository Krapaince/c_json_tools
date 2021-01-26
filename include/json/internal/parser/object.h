#ifndef JSON_INTERNAL_PARSER_OBJECT_H_
#define JSON_INTERNAL_PARSER_OBJECT_H_

#include <json/internal/typedef/object.h>
#include <json/internal/typedef/parser.h>
#include <json/internal/typedef/token.h>

// Check if a already exist in an object.
// obj mustn't be NULL
//
// Return:
//   If a key already exists JSON_EXIT_SUCCESS
//   Else if there isn't this key JSON_EXIT_FAILURE
//
int json_does_key_already_exist(json_object_t const* obj, token_t const* token);

// Parse and add the array to the object
int json_get_array_in_object(json_object_t* obj, parser_t* parser,
                             token_type_t* expected);

// Parse and add the object to the object
int json_get_object_in_object(json_object_t* obj, parser_t* parser,
                              token_type_t* expected);

// Parses the file to find the next token and evalutes it for the json grammar
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_get_next_token_object(json_object_t const* obj, parser_t* parser,
                               token_type_t* expected);

// Main function to call to parse an object
//
// Return:
//   Failure: NULL
//   Success: a pointer to an allocated json_object_t structure
//
json_object_t* json_parse_object(parser_t* parser, token_type_t* expected);

#endif /* !JSON_INTERNAL_PARSER_OBJECT_H_ */
