#ifndef JSON_INTERNAL_ESCAPE_CHARACTER_H_
#define JSON_INTERNAL_ESCAPE_CHARACTER_H_

#include <json/internal/typedef/escape_character.h>

#define ESCAPE_CHARACTER "\"\\/\b\f\n\r\t"

typedef enum
{
    D_QUOTE = 0,
    BACKSLASH,
    SLASH,
    BACKSPACE,
    FORMFEED,
    LINEFEED,
    CARRIAGE_RETURN,
    HORIZONTAL_TAB,

    ESC_CHAR_COUNT,
} esc_char_index_t;

escape_character_t const* json_find_esc_char_from_char(char c);
escape_character_t const* json_find_esc_char_from_str(char const* s);

#endif /* !JSON_INTERNAL_ESCAPE_CHARACTER_H_ */
