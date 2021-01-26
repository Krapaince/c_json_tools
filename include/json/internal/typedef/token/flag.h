#ifndef JSON_INTERNAL_TYPEDEF_TOKEN_FLAG_H_
#define JSON_INTERNAL_TYPEDEF_TOKEN_FLAG_H_

#include <json/internal/typedef/token.h>

typedef struct
{
    token_type_t type;
    void (*ptr)(token_type_t* expected);
} selector_token_flag_t;

#endif /* !JSON_INTERNAL_TYPEDEF_TOKEN_FLAG_H_ */
