/*
** EPITECH PROJECT, 2020
** json library
** File description:
** array parser function prototype
*/

#include <typedef/array.h>
#include <typedef/parser.h>
#include <typedef/token.h>

// Parse and add the array to the array
int json_get_array_in_array(json_array_t* array, parser_t* parser,
                            token_type_t* expected);

// Parse and add the object to the array
int json_get_object_in_array(json_array_t* array, parser_t* parser,
                             token_type_t* expected);

// Parses the file to find the next token and evalutes it for the json grammar
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_get_next_token_array(parser_t* parser, token_type_t* expected);

// Main function to call to parse an array
// Return:
//   Failure: NULL
//   Success: a pointer to an allocated json_array_t structure
//
json_array_t* json_parse_array(parser_t* parser, token_type_t* expected);
