/*
** EPITECH PROJECT, 2020
** json library
** File description:
** custom strtok.h
*/

#ifndef JSON_STRTOK_H_
#define JSON_STRTOK_H_

#include <stddef.h>

// This custom strtok as for purpose to create tokens for the json library.
// my_strtok will only be call to extract a token of a key or a value of type
// string or number.
//
// str        -> the string to parse
// index      -> index in the string
// delimiters -> is a string of character that represent delimiters
// quote -> the quote characerter
// token -> a pointer in which the token will be return
//
// Return:
//   Failure: EXIT_FAILURE
//   Success: EXIT_SUCCESS
//
int json_strtok(char const* str, size_t* index, char const* delimiters,
                char quote, char** token);

#endif /* !JSON_STRTOK_H_ */
