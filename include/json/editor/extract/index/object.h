#ifndef JSON_EXTRACT_INDEX_OBJECT_H_
#define JSON_EXTRACT_INDEX_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

/**
 * @defgroup EditorExtractIndexObject
 * @{
 */

int json_object_extract_bool_by_index(json_object_t* object, size_t index,
                                      bool* value);

int json_object_extract_nb_by_index(json_object_t* object, size_t index,
                                    int* value);

/**
 * @note The ownership of the returned value is tranfered to the caller
 */
int json_object_extract_string_by_index(json_object_t* object, size_t index,
                                        char** value);

/**
 * @note The ownership of the returned value is tranfered to the caller
 */
int json_object_extract_str_by_index(json_object_t* object, size_t index,
                                     str_t* value);

/**
 * @note The ownership of the returned value is tranfered to the caller
 */
int json_object_extract_object_by_index(json_object_t* object, size_t index,
                                        json_object_t** value);

/**
 * @note The ownership of the returned value is tranfered to the caller
 */
int json_object_extract_array_by_index(json_object_t* object, size_t index,
                                       json_array_t** value);

/** @} */

#endif /* !JSON_EXTRACT_INDEX_OBJECT_H_ */
