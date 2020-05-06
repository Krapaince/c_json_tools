/*
** EPITECH PROJECT, 2020
** json library
** File description:
** write
*/

#ifndef JSON_GENERATOR_WRITE_H_
#define JSON_GENERATOR_WRITE_H_

#include <typedef/generator.h>
#include <typedef/token.h>
#include <typedef/type.h>

// flushs the buffer of generator
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// set json_errno in case of failure
int json_write(generator_t* generator);

// appends to the buffer of generator and flushs it if necessary
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// set json_errno in case of failure
//
int json_write_buffer(generator_t* generator, char const* str, size_t len);

int json_write_nb(generator_t* generator, int nb);
int json_write_str(generator_t* generator, str_t const* str);
int json_write_type(generator_t* generator, token_type_t type);
int json_write_union_value(generator_t* generator,
                           json_union_value_t const* value, json_type_t type);

int json_write_indent(generator_t* generator);
int json_write_space(generator_t* generator);
int json_write_new_line(generator_t* generator);

#endif /* !JSON_GENERATOR_WRITE_H_ */
