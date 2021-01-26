#include <json/internal/error.h>
#include <json/internal/parser/token/flag.h>
#include <json/internal/parser/token/flag/array.h>
#include <json/internal/typedef/token.h>
#include <json/internal/typedef/token/flag.h>

static selector_token_flag_t const array_flags[] = {
    {T_L_SQ_BRACKET, json_update_token_flag_array_l_sq_bracket},
    {T_R_SQ_BRACKET, json_update_token_flag_array_r_sq_bracket},
    {T_L_BRACKET, json_update_token_flag_array_l_bracket},
    {T_R_BRACKET, json_update_token_flag_array_r_bracket},
    {T_COMMA, json_update_token_flag_array_comma},
    {T_TYPE, json_update_token_flag_array_type},
    {T_ERROR, NULL}};

void json_set_token_flag_array(token_type_t* expected)
{
    json_update_token_flag_array_l_sq_bracket(expected);
}

void json_set_token_flag_array_after_element(token_type_t* expected)
{
    *expected |= T_COMMA | T_R_SQ_BRACKET;
}

int json_update_token_flag_array(token_type_t type, token_type_t* expected)
{
    size_t i = 0;

    if (!(*expected & type))
    {
        json_set_flag_error_synthax(expected);
        return JSON_EF;
    }
    while (array_flags[i].ptr)
    {
        if (array_flags[i].type & type)
        {
            array_flags[i].ptr(expected);
            return JSON_ES;
        }
        ++i;
    }
    json_set_flag_error_synthax(expected);
    return JSON_EF;
}
