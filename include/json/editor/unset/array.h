#ifndef JSON_EDITOR_UNSET_ARRAY_H_
#define JSON_EDITOR_UNSET_ARRAY_H_

#include <json/type/array.h>

/**
 * @defgroup EditorUnsetArrayIndex
 * @{
 */

int json_array_unset_element_by_index(json_array_t* array, size_t index);

/** @} */

/**
 * @defgroup EditorUnsetArrayValue
 * @{
 */

int json_array_unset_elements_by_value_bool(json_array_t* array, bool value);

int json_array_unset_elements_by_value_nb(json_array_t* array, int value);

int json_array_unset_elements_by_value_str(json_array_t* array,
                                           str_t const* value);

int json_array_unset_elements_by_null(json_array_t* array);

int json_array_unset_elements_by_value_object(json_array_t* array,
                                              json_object_t* value);

int json_array_unset_elements_by_value_array(json_array_t* array,
                                             json_array_t* value);

/** @} */

#endif /* !JSON_EDITOR_UNSET_ARRAY_H_ */
