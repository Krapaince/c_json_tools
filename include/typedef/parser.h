/*
** EPITECH PROJECT, 2020
** json library
** File description:
** parser
*/

#ifndef JSON_TYPEDEF_PARSER_H_
#define JSON_TYPEDEF_PARSER_H_

#include <stddef.h>
#include <stdio.h>

#include "token.h"
#include "type.h"

#define WHITESPACES       " \t\r\n"
#define STRUCTURAL_TOKENS "[]{},:"

typedef enum
{
    PARSER_STRING,
    PARSER_FILE,
} parser_type_t;

typedef struct
{
    char const* buffer;
} parser_str_t;

typedef struct
{
    FILE* fstream;
    char* buffer;
    size_t buffer_size;
} parser_file_t;

typedef union
{
    parser_str_t str;
    parser_file_t file;
} parser_source_t;

typedef struct
{
    parser_type_t type;

    size_t index;
    size_t line;
    parser_source_t source;

    str_t key;
    token_t token;

    char const* whitespaces;
    char const* delimiters;
    char quote;
} parser_t;

#endif /* !JSON_TYPEDEF_PARSER_H_ */
