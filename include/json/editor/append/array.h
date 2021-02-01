#ifndef JSON_EDITOR_APPEND_ARRAY_H_
#define JSON_EDITOR_APPEND_ARRAY_H_

#include <json/internal/error.h>
#include <json/type/array.h>

/**
 * @defgroup EditorAppendArray
 * @{
 */

int json_array_append_bool(json_array_t* array, bool value);

int json_array_append_nb(json_array_t* array, int value);

/**
 *The added value is a copy of ``value``.
 */
int json_array_append_str_dup(json_array_t* array, char const* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_array_append_str(json_array_t* array, char* value);

int json_array_append_null(json_array_t* array);

/**
 * The function takes ownership of the value's pointer.
 */
int json_array_append_object(json_array_t* array, json_object_t* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_array_append_array(json_array_t* array, json_array_t* value);

/** @} */

#endif /* !JSON_INTERNAL_EDITOR_APPEND_ARRAY_H_ */
