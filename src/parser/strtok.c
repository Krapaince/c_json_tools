#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <json/internal/error.h>
#include <json/internal/escape_character.h>
#include <json/internal/strtok.h>

static void skip_delimiter(char const* str, size_t* i_str,
                           char const* delimiters)
{
    size_t i = *i_str;

    while (str[i] && index(delimiters, str[i]))
    {
        ++i;
    }
    *i_str = i;
}

static size_t strtok_len_in_quote(char const* str, char quote, size_t* len_str)
{
    size_t i = 1;
    size_t len = 1;
    escape_character_t const* esc_char;

    while (str[i])
    {
        esc_char = json_find_esc_char_from_str(&str[i]);
        if (esc_char)
        {
            i += esc_char->len;
        }
        else if (str[i] == quote)
        {
            *len_str = i + 1;
            return len + 1;
        }
        else
        {
            ++i;
        }
        ++len;
    }
    json_errno = JSON_E_UNMATCHED_QUOTE;
    return 0;
}

static size_t strtok_len(char const* str, char const* delimiters, char quote,
                         size_t* len_str)
{
    size_t len = 0;
    size_t i = 0;
    escape_character_t const* esc_char;

    if (str[0] == quote)
        return strtok_len_in_quote(str, quote, len_str);
    while (str[i])
    {
        if (index(delimiters, str[i]) != NULL || str[i] == quote)
        {
            *len_str = i;
            return len;
        }
        esc_char = json_find_esc_char_from_str(&str[i]);
        if (esc_char)
        {
            i += esc_char->len;
        }
        else
        {
            ++i;
        }
        ++len;
    }
    *len_str = i;
    return len;
}

static void copy_token(char const* str, char* token, size_t len)
{
    size_t i_str = 0;
    size_t i_tok = 0;
    escape_character_t const* esc_char;

    while (i_tok < len)
    {
        esc_char = json_find_esc_char_from_str(&str[i_str]);
        if (esc_char)
        {
            token[i_tok] = esc_char->code;
            i_str += esc_char->len;
        }
        else
        {
            token[i_tok] = str[i_str];
            ++i_str;
        }
        ++i_tok;
    }
}

int json_strtok(char const* str, size_t* index, char const* delimiters,
                char quote, char** token)
{
    size_t len;
    size_t len_str;
    int ret = JSON_ES;

    skip_delimiter(str, index, delimiters);
    len = strtok_len(&str[*index], delimiters, quote, &len_str);
    if (json_errno != JSON_E_DEFAULT)
    {
        return JSON_EF;
    }
    *token = malloc(sizeof(char) * (len + 1));
    if (*token == NULL)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EF;
    }
    else
    {
        copy_token(&str[*index], *token, len);
        (*token)[len] = '\0';
        *index += len_str;
    }
    return ret;
}
