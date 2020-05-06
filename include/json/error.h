/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json error export
*/

#ifndef JSON_EXPORT_ERROR_H_
#define JSON_EXPORT_ERROR_H_

#include <stddef.h>
#include <stdio.h>

#include <typedef/error_code.h>

extern unsigned char* json_errno_location(void);

// Access to the value of the error
#define json_errno (*json_errno_location())

// Write into the stream the error details
void json_print_error(FILE* stream);

#endif /* !JSON_EXPORT_ERROR_H_ */
