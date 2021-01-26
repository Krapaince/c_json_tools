#ifndef JSON_INTERNAL_PARSER_TOKEN_FLAG_OBJECT_H_
#define JSON_INTERNAL_PARSER_TOKEN_FLAG_OBJECT_H_

#include <json/internal/typedef/token.h>

void json_update_token_flag_obj_l_sq_bracket(token_type_t* expected);
void json_update_token_flag_obj_r_sq_bracket(token_type_t* expected);
void json_update_token_flag_obj_l_bracket(token_type_t* expected);
void json_update_token_flag_obj_r_bracket(token_type_t* expected);

void json_update_token_flag_obj_key(token_type_t* expected);
void json_update_token_flag_obj_colon(token_type_t* expected);
void json_update_token_flag_obj_comma(token_type_t* expected);
void json_update_token_flag_obj_type(token_type_t* expected);

void json_set_token_flag_obj(token_type_t* expected);
void json_set_token_flag_obj_after_element(token_type_t* expected);

// Checks if type is in expected and updates expected to the expected type after
// type. If type isn't in expected, expected will be set to T_ERROR and
// json_errno will be set.
int json_update_token_flag_obj(token_type_t type, token_type_t* expected);

#endif /* !JSON_INTERNAL_PARSER_TOKEN_FLAG_OBJECT_H_ */
