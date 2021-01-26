#include <criterion/criterion.h>

#include <json/internal/parser/token/flag/object.h>

Test(json_set_token_flag_obj, test_json_set_token_flag)
{
    token_type_t expected;

    json_set_token_flag_obj(&expected);
    cr_expect(expected = (T_R_BRACKET | T_KEY));
}

Test(json_update_token_flag_obj_l_sq_bracket,
     test_update_token_flag_obj_l_sq_bracket)
{
    token_type_t expected;

    json_update_token_flag_obj_l_sq_bracket(&expected);
    cr_expect(expected = (T_TYPE | T_R_SQ_BRACKET));
}

Test(json_update_token_flag_obj_r_sq_bracket,
     test_update_token_flag_obj_r_sq_bracket)
{
    token_type_t expected;

    json_update_token_flag_obj_r_sq_bracket(&expected);
    cr_expect(expected = (T_COMMA | T_R_BRACKET));
}

Test(json_update_token_flag_obj_l_bracket, test_update_token_flag_obj_l_bracket)
{
    token_type_t expected;

    json_update_token_flag_obj_l_bracket(&expected);
    cr_expect(expected = (T_KEY | T_R_BRACKET));
}

Test(json_update_token_flag_obj_r_bracket, test_update_token_flag_obj_r_bracket)
{
    token_type_t expected;

    json_update_token_flag_obj_r_bracket(&expected);
    cr_expect(expected = (T_COMMA | T_R_BRACKET));
}

Test(json_update_token_flag_obj_key, test_update_token_flag_obj_key)
{
    token_type_t expected;

    json_update_token_flag_obj_key(&expected);
    cr_expect(expected = (T_COLON));
}

Test(json_update_token_flag_obj_colon, test_update_token_flag_obj_colon)
{
    token_type_t expected;

    json_update_token_flag_obj_colon(&expected);
    cr_expect(expected = (T_TYPE | T_L_BRACKET | T_L_SQ_BRACKET));
}

Test(json_update_token_flag_obj_comma, test_update_token_flag_obj_comma)
{
    token_type_t expected;

    json_update_token_flag_obj_comma(&expected);
    cr_expect(expected = T_KEY);
}

Test(json_update_token_flag_obj_type, test_update_token_flag_obj_type)
{
    token_type_t expected;

    json_update_token_flag_obj_type(&expected);
    cr_expect(expected = (T_COMMA | T_R_BRACKET));
}
