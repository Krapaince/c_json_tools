#ifndef JSON_EDITOR_APPEND_OBJECT_H_
#define JSON_EDITOR_APPEND_OBJECT_H_

#include <json/internal/error.h>
#include <json/type/object.h>

/**
 * @defgroup EditorAppendObject
 * @{
 */

int json_object_append_bool(json_object_t* obj, char const* key, bool value);

int json_object_append_nb(json_object_t* obj, char const* key, int value);

/**
 * The added value is a copy of ``value``.
 */
int json_object_append_str_dup(json_object_t* obj, char const* key,
                               char const* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_object_append_str(json_object_t* obj, char const* key, char* value);

int json_object_append_null(json_object_t* obj, char const* key);

/**
 * The function takes ownership of the value's pointer.
 */
int json_object_append_object(json_object_t* obj, char const* key,
                              json_object_t* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_object_append_array(json_object_t* obj, char const* key,
                             json_array_t* value);

/** @} */

#endif /* !JSON_EDITOR_APPEND_OBJECT_H_ */
