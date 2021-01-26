#include <json/internal/typedef/token.h>

void json_update_token_flag_obj_key(token_type_t* expected)
{
    *expected = T_COLON;
}

void json_update_token_flag_obj_colon(token_type_t* expected)
{
    *expected = T_TYPE | T_L_SQ_BRACKET | T_L_BRACKET;
}

void json_update_token_flag_obj_comma(token_type_t* expected)
{
    *expected = T_KEY;
}

void json_update_token_flag_obj_type(token_type_t* expected)
{
    *expected = T_COMMA | T_R_BRACKET;
}
