#include <json/internal/typedef/token.h>

void json_update_token_flag_array_comma(token_type_t* expected)
{
    *expected = T_TYPE | T_L_SQ_BRACKET | T_L_BRACKET;
}

void json_update_token_flag_array_type(token_type_t* expected)
{
    *expected = T_COMMA | T_R_SQ_BRACKET;
}
