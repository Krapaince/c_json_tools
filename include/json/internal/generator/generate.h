#ifndef JSON_INTERNAL_GENERATOR_GENERATE_H_
#define JSON_INTERNAL_GENERATOR_GENERATE_H_

#include <json/internal/typedef/generator.h>
#include <json/internal/typedef/token.h>
#include <json/internal/typedef/type.h>

// Flushs the buffer to the output.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// Set json_errno in case of failure.
int json_generate_to_output(generator_t* generator);

// Appends to the buffer of generator and flushs it if necessary.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// Set json_errno in case of failure.
//
int json_generate_to_buffer(generator_t* generator, char const* str,
                            size_t len);

int json_generate_nb(generator_t* generator, int nb);
int json_generate_str(generator_t* generator, str_t const* str);
int json_generate_type(generator_t* generator, token_type_t type);
int json_generate_union_value(generator_t* generator,
                              json_union_value_t const* value,
                              json_type_t type);

int json_generate_indent(generator_t* generator);
int json_generate_space(generator_t* generator);
int json_generate_new_line(generator_t* generator);

#endif /* !JSON_INTERNAL_GENERATOR_GENERATE_H_ */
