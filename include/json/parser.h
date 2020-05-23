/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json parser function
*/

#ifndef JSON_EXPORT_PARSER_H_
#define JSON_EXPORT_PARSER_H_

#include <json/type/array.h>
#include <json/type/object.h>

// Parses a JSON object by reading the file descriptor. When the end of the
// object if reach, json_object_parse_from_fd returns the object and let the
// file descriptor open.
//
// Return:
//   Failure: NULL
//   Success: A pointer to an allocated json_object_t structure
//
//   In case of failure json_errno is set.
//
json_object_t* json_object_parse_from_fd(int fd);

// Parses a JSON array by reading the file descriptor. When the end of the
// object if reach, json_object_parse_from_fd returns the object and let the
// file descriptor open.
//
// Return:
//   Failure: NULL
//   Success: A pointer to an allocated json_object_t structure
//
//   In case of failure json_errno is set.
//
json_array_t* json_array_parse_from_fd(int fd);

// Parses a JSON object by reading in the filepath. When the end of the
// object if reach, json_object_parse_from_filepath checks that there is only
// whitespace characters after the object. If there isn't only whitespace
// characters after the object the function fails.
//
// Return:
//   Failure: NULL
//   Success: A pointer to an allocated json_object_t structure
//
//   In case of failure json_errno is set.
//
json_object_t* json_object_parse_from_filepath(char const* filepath);

// Parses a JSON array by reading in the filepath. When the end of the
// array if reach, json_array_parse_from_filepath checks that there is only
// whitespace characters after the array. If there isn't only whitespace
// characters after the array the function fails.
//
// Return:
//   Failure: NULL
//   Success: A pointer to an allocated json_array_t structure
//
//   In case of failure json_errno is set.
//
json_array_t* json_array_parse_from_filepath(char const* filepath);

// Parses a JSON object thanks to str. If the function succeed and index is not
// null, *index will be set with the index at which the parser stopped in str.
//
// Return:
//   Failure: NULL
//   Success: A pointer to an allocated json_object_t structure
//
//   In case of failure json_errno is set.
//
json_object_t* json_object_parse_from_str(char const* str, size_t* index);

// Parses a JSON array thanks to str. If the function succeed and index is not
// null, *index will be set with the index at which the parser stopped in str.
//
// Return:
//   Failure: NULL
//   Success: A pointer to an allocated json_object_t structure
//
//   In case of failure json_errno is set.
//
json_array_t* json_array_parse_from_str(char const* str, size_t* index);

#endif /* !JSON_EXPORT_PARSER_H_ */
