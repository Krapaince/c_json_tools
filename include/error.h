/*
** EPITECH PROJECT, 2020
** json library
** File description:
** error.h
*/

#ifndef JSON_ERROR_H_
#define JSON_ERROR_H_

#include <stddef.h>

#include <typedef/error.h>
#include <typedef/error_code.h>

extern unsigned char* json_errno_location(void);
#define json_errno (*json_errno_location())

void json_errno_reset(void);

extern size_t* json_error_line_location(void);
#define json_error_line (*json_error_line_location())

#endif /* !JSON_ERROR_H_ */
