#ifndef JSON_EDITOR_SET_KEY_OBJECT_H_
#define JSON_EDITOR_SET_KEY_OBJECT_H_

#include <json/error.h>
#include <json/type/array.h>
#include <json/type/object.h>

/**
 * @defgroup EditorSetKeyObject
 * @{
 */

int json_object_set_bool_by_key(json_object_t* obj, char const* key,
                                bool value);

int json_object_set_nb_by_key(json_object_t* obj, char const* key, int value);

int json_object_set_str_dup_by_key(json_object_t* obj, char const* key,
                                   char const* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_object_set_str_by_key(json_object_t* obj, char const* key,
                               char* value);

int json_object_set_null_by_key(json_object_t* obj, char const* key);

/**
 * The function takes ownership of the value's pointer.
 */
int json_object_set_object_by_key(json_object_t* obj, char const* key,
                                  json_object_t* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_object_set_array_by_key(json_object_t* obj, char const* key,
                                 json_array_t* value);

/** @} */

#endif /* !JSON_EDITOR_SET_KEY_OBJECT_H_ */
