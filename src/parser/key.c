#include <stddef.h>
#include <string.h>

#include <json/internal/error.h>
#include <json/internal/typedef/object.h>
#include <json/internal/typedef/token.h>

int json_does_key_already_exist(json_object_t const* obj, token_t const* token)
{
    size_t i = 0;
    str_t const* key;

    while (i < obj->len)
    {
        key = &obj->elements[i].key;
        if (key->len == token->length - 2 &&
            strncmp(&token->value[1], key->value, key->len) == 0)
        {
            json_errno = JSON_E_KEY_DUPLICATED;
            return JSON_EXIT_FAILURE;
        }
        ++i;
    }
    return JSON_EXIT_SUCCESS;
}
