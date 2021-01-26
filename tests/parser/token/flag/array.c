#include <criterion/criterion.h>

#include <json/internal/parser/token/flag/array.h>

Test(json_set_token_flag_array, test_update_token_flag_array)
{
    token_type_t expected;

    json_set_token_flag_array(&expected);
    cr_expect(expected = (T_TYPE | T_L_BRACKET | T_L_SQ_BRACKET));
}

Test(json_update_token_flag_array_l_sq_bracket,
     test_update_token_flag_array_l_sq_bracket)
{
    token_type_t expected;

    json_update_token_flag_array_l_sq_bracket(&expected);
    cr_expect(expected = (T_TYPE | T_L_BRACKET | T_L_SQ_BRACKET));
}

Test(json_update_token_flag_array_r_sq_bracket,
     test_update_token_flag_array_r_sq_bracket)
{
    token_type_t expected;

    json_update_token_flag_array_r_sq_bracket(&expected);
    cr_expect(expected = (T_COMMA | T_R_SQ_BRACKET));
}

Test(json_update_token_flag_array_l_bracket,
     test_update_token_flag_array_l_bracket)
{
    token_type_t expected;

    json_update_token_flag_array_l_bracket(&expected);
    cr_expect(expected = (T_KEY | T_R_BRACKET));
}

Test(json_update_token_flag_array_r_bracket,
     test_update_token_flag_array_r_bracket)
{
    token_type_t expected;

    json_update_token_flag_array_r_bracket(&expected);
    cr_expect(expected = (T_COMMA | T_R_BRACKET));
}

Test(json_update_token_flag_array_comma, test_update_token_flag_array_comma)
{
    token_type_t expected;

    json_update_token_flag_array_r_bracket(&expected);
    cr_expect(expected = (T_TYPE | T_L_SQ_BRACKET | T_R_BRACKET));
}

Test(json_update_token_flag_array_type, test_update_token_flag_array_tpye)
{
    token_type_t expected;

    json_update_token_flag_array_r_bracket(&expected);
    cr_expect(expected = (T_COMMA | T_R_BRACKET));
}
