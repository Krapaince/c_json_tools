#include <json/internal/error.h>
#include <json/internal/typedef/token.h>

void json_set_flag_error_synthax(token_type_t* expected)
{
    *expected = T_ERROR;
    json_errno = JSON_E_SYNTHAX;
}
