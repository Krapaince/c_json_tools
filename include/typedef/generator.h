/*
** EPITECH PROJECT, 2020
** json library
** File description:
** struct generator
*/

#ifndef JSON_TYPEDEF_GENERATOR_H_
#define JSON_TYPEDEF_GENERATOR_H_

#include <stdlib.h>

#define GENERATOR_BUFFER_SIZE 4096

typedef enum
{
    GENERATOR_OUTPUT_STRING,
    GENERATOR_OUTPUT_FILE
} generator_output_type_t;

typedef struct
{
    generator_output_type_t type;
    union
    {
        int fd;
    };
} generator_output_t;

typedef enum
{
    TABULATION = '\t',
    SPACE = ' ',
    DISABLE = '\0'
} indent_type_t;

typedef struct
{
    indent_type_t type;
    size_t indent_size;
} generator_setting_t;

typedef struct
{
    char* value;
    size_t len;
    size_t len_alloc;
} generator_buffer_t;

typedef struct
{
    generator_output_t output;

    indent_type_t type;
    char* indent;
    size_t len_indent;
    size_t depth;

    generator_buffer_t buffer;
} generator_t;

#endif /* !JSON_TYPEDEF_GENERATOR_H_ */
