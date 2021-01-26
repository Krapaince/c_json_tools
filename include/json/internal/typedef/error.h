#ifndef JSON_INTERNAL_TYPEDEF_ERROR_H_
#define JSON_INTERNAL_TYPEDEF_ERROR_H_

#define JSON_ERROR_PREFIX "Json library: "
#define JSON_ERROR_LINE   "(line: %zd)"

#include <json/internal/typedef/error_code.h>

typedef enum
{
    NONE,
    PERROR,
    LINE
} json_error_requirement_t;

typedef struct
{
    unsigned char code;
    char const* str;
    json_error_requirement_t requirement;
} json_error_t;

#endif /* !JSON_INTERNAL_TYPEDEF_ERROR_H_ */
