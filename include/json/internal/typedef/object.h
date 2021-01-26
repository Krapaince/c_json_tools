#ifndef JSON_INTERNAL_TYPEDEF_OBJECT_H_
#define JSON_INTERNAL_TYPEDEF_OBJECT_H_

#include <stddef.h>

#include "type.h"

typedef struct json_object_element_s
{
    str_t key;
    json_type_t type;
    json_union_value_t value;
} json_object_element_t;

typedef struct json_object_s
{
    json_object_element_t* elements;
    size_t len;
    size_t len_alloc;
} json_object_t;

#endif /* !JSON_INTERNAL_TYPEDEF_OBJECT_H_ */
