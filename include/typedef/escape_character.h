/*
** EPITECH PROJECT, 2020
** json library
** File description:
** escape_character.h
*/

#ifndef JSON_TYPEDEF_ESCAPE_CHARACTER_H_
#define JSON_TYPEDEF_ESCAPE_CHARACTER_H_

#include <stddef.h>

typedef struct
{
    char const code;
    char const* str;
    size_t len;
} escape_character_t;

#endif /* !JSON_TYPEDEF_ESCAPE_CHARACTER_H_ */
