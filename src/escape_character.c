/*
** EPITECH PROJECT, 2020
** json library
** File description:
** escape_character.c
*/

#include <stdlib.h>
#include <string.h>

#include <escape_character.h>
#include <typedef/escape_character.h>

static escape_character_t const escape_chars[] = {
    {ESCAPE_CHARACTER[D_QUOTE], "\\\"", 2},
    {ESCAPE_CHARACTER[BACKSLASH], "\\\\", 2},
    {ESCAPE_CHARACTER[SLASH], "\\/", 2},
    {ESCAPE_CHARACTER[BACKSPACE], "\\b", 2},
    {ESCAPE_CHARACTER[FORMFEED], "\\f", 2},
    {ESCAPE_CHARACTER[LINEFEED], "\\n", 2},
    {ESCAPE_CHARACTER[CARRIAGE_RETURN], "\\r", 2},
    {ESCAPE_CHARACTER[HORIZONTAL_TAB], "\\t", 2}};

escape_character_t const* json_find_esc_char_from_char(char c)
{
    size_t i = 0;
    escape_character_t const* ptr;

    while (i < ESC_CHAR_COUNT)
    {
        ptr = &escape_chars[i];
        if (ptr->code == c)
        {
            return ptr;
        }
        ++i;
    }
    return NULL;
}

escape_character_t const* json_find_esc_char_from_str(char const* s)
{
    size_t i = 0;
    escape_character_t const* ptr;

    while (i < ESC_CHAR_COUNT)
    {
        ptr = &escape_chars[i];
        if (strncmp(s, ptr->str, ptr->len) == 0)
        {
            return ptr;
        }
        ++i;
    }
    return NULL;
}
