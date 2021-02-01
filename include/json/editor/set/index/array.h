#ifndef JSON_SET_INDEX_ARRAY_H_
#define JSON_SET_INDEX_ARRAY_H_

#include <json/error.h>
#include <json/type/array.h>

/**
 * @defgroup EditorSetIndexArray
 * @{
 */

int json_array_set_bool_by_index(json_array_t* array, size_t index, bool value);

int json_array_set_nb_by_index(json_array_t* array, size_t index, int value);

/**
 * The value is duplicated if the function fails json_errno is set to
 * ``JSON_E_SYS_FAILURE``.
 */
int json_array_set_str_dup_by_index(json_array_t* array, size_t index,
                                    char const* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_array_set_str_by_index(json_array_t* array, size_t index, char* value);

int json_array_set_null_by_index(json_array_t* array, size_t index);

/**
 * The function takes ownership of the value's pointer.
 */
int json_array_set_object_by_index(json_array_t* array, size_t index,
                                   json_object_t* value);

/**
 * The function takes ownership of the value's pointer.
 */
int json_array_set_array_by_index(json_array_t* array, size_t index,
                                  json_array_t* value);

/** @} */

#endif /* !JSON_SET_INDEX_ARRAY_H_ */
