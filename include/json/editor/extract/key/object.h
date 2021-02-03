#ifndef JSON_EDITOR_EXTRACT_KEY_OBJECT_H_
#define JSON_EDITOR_EXTRACT_KEY_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

/**
 * @defgroup EditorExtractKeyObject
 * @{
 */

int json_object_extract_bool_by_key(json_object_t* obj, char const* key,
                                    bool* value);

int json_object_extract_nb_by_key(json_object_t* obj, char const* key,
                                  int* value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_object_extract_string_by_key(json_object_t* obj, char const* key,
                                      char** value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_object_extract_str_by_key(json_object_t* obj, char const* key,
                                   str_t* value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_object_extract_object_by_key(json_object_t* obj, char const* key,
                                      json_object_t** value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_object_extract_array_by_key(json_object_t* obj, char const* key,
                                     json_array_t** value);

/** @} */

#endif /* !JSON_EDITOR_EXTRACT_KEY_OBJECT_H_ */
