#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include <json/internal/error.h>

static const json_error_t errors[] = {
    {JSON_E_DEFAULT, "No error", NONE},
    {JSON_E_SYS_FAILURE, "System function error: %s", PERROR},
    {JSON_E_UNMATCHED_QUOTE, "Unmatched quote " JSON_ERROR_LINE, LINE},
    {JSON_E_UNKNOW_TYPE, "Unknow token type " JSON_ERROR_LINE, LINE},
    {JSON_E_END_OF_FILE, "End of file", NONE},
    {JSON_E_SYNTHAX, "Synthax error " JSON_ERROR_LINE, LINE},
    {JSON_E_KEY_DUPLICATED, "Diplicated key " JSON_ERROR_LINE, LINE},
    {JSON_E_INVALID_EOF, "Unexpected end of file", NONE},
    {JSON_E_KEY_ALREADY_EXIST, "Key already exist", NONE},
    {JSON_E_COUNT, NULL, NONE}};

unsigned char* json_errno_location(void)
{
    static unsigned char var_json_errno = 0;

    return (&var_json_errno);
}

void json_errno_reset(void)
{
    json_errno = JSON_E_DEFAULT;
}

size_t* json_error_line_location(void)
{
    static size_t line = 0;

    return (&line);
}

static void json_print_requirement(json_error_t const* error, FILE* stream)
{
    switch (error->requirement)
    {
        case NONE:
            fprintf(stream, error->str);
            break;
        case PERROR:
            fprintf(stream, error->str, strerror(errno));
            break;
        case LINE:
            fprintf(stream, error->str, json_error_line);
            break;
    }
    fprintf(stream, "\n");
}

void json_print_error(FILE* stream)
{
    size_t i = 0;
    json_error_t const* error = &errors[i];

    while (i < JSON_E_COUNT)
    {
        if (error->code == json_errno)
        {
            json_print_requirement(&errors[i], stream);
            return;
        }
        ++i;
        error = &errors[i];
    }
}
