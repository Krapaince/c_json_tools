#ifndef JSON_INTERNAL_TYPEDEF_ARRAY_H_
#define JSON_INTERNAL_TYPEDEF_ARRAY_H_

#include <stddef.h>

#include <json/internal/typedef/type.h>

typedef struct
{
    json_type_t type;
    json_union_value_t value;
} json_array_element_t;

typedef struct json_array_s
{
    json_array_element_t* elements;
    size_t len;
    size_t len_alloc;
} json_array_t;

#endif /* !JSON_INTERNAL_TYPEDEF_ARRAY_H_ */
