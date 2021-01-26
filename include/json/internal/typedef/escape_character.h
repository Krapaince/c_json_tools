#ifndef JSON_INTERNAL_TYPEDEF_ESCAPE_CHARACTER_H_
#define JSON_INTERNAL_TYPEDEF_ESCAPE_CHARACTER_H_

#include <stddef.h>

typedef struct
{
    char const code;
    char const* str;
    size_t len;
} escape_character_t;

#endif /* !JSON_INTERNAL_TYPEDEF_ESCAPE_CHARACTER_H_ */
