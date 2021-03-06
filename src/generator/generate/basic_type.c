#include <limits.h>
#include <stdio.h>

#include <json/internal/error.h>
#include <json/internal/escape_character.h>
#include <json/internal/generator/generate.h>
#include <json/internal/typedef/escape_character.h>
#include <json/internal/typedef/generator.h>
#include <json/internal/typedef/type.h>

static size_t json_compute_nb_len(int nb)
{
    size_t len = 1;
    size_t const int_min_len = 11;

    if (nb < 0)
    {
        if (nb == INT_MIN)
        {
            return int_min_len;
        }
        ++len;
        nb *= -1;
    }
    while (10 <= nb)
    {
        ++len;
        nb /= 10;
    }
    return len;
}

int json_generate_nb(generator_t* generator, int nb)
{
    size_t nb_len = json_compute_nb_len(nb);
    char buffer[nb_len];

    sprintf(buffer, "%d", nb);
    return json_generate_to_buffer(generator, buffer, nb_len);
}

int json_generate_str(generator_t* generator, str_t const* str)
{
    escape_character_t const* esc_char;
    escape_character_t const* quote =
        json_find_esc_char_from_char(ESCAPE_CHARACTER[D_QUOTE]);
    size_t i = 0;
    int ret = json_generate_to_buffer(generator, &quote->code, 1);

    while (i < str->len && ret == JSON_ES)
    {
        esc_char = json_find_esc_char_from_char(str->value[i]);
        if (esc_char)
        {
            ret = json_generate_to_buffer(generator, esc_char->str,
                                          esc_char->len);
        }
        else
        {
            ret = json_generate_to_buffer(generator, &str->value[i], 1);
        }
        ++i;
    }
    if (ret == JSON_ES)
    {
        ret = json_generate_to_buffer(generator, &quote->code, 1);
    }
    return ret;
}
