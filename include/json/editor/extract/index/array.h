#ifndef JSON_EDITOR_EXTRACT_INDEX_ARRAY_H_
#define JSON_EDITOR_EXTRACT_INDEX_ARRAY_H_

#include <json/error.h>
#include <json/type/array.h>

/**
 * @defgroup EditorExtractIndexArray
 * @{
 */

int json_array_extract_bool_by_index(json_array_t* array, size_t index,
                                     bool* value);

int json_array_extract_nb_by_index(json_array_t* array, size_t index,
                                   int* value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_array_extract_string_by_index(json_array_t* array, size_t index,
                                       char** value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_array_extract_str_by_index(json_array_t* array, size_t index,
                                    str_t* value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_array_extract_object_by_index(json_array_t* array, size_t index,
                                       json_object_t** value);

/**
 * @note The ownership of the returned value is transferred to the caller.
 */
int json_array_extract_array_by_index(json_array_t* array, size_t index,
                                      json_array_t** value);

/** @} */

#endif /* !JSON_EDITOR_EXTRACT_INDEX_ARRAY_H_ */
