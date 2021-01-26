#ifndef JSON_INTERNAL_GETTERS_INDEX_ARRAY_H_
#define JSON_INTERNAL_GETTERS_INDEX_ARRAY_H_

#include <json/internal/error.h>
#include <json/internal/typedef/array.h>

// Gets the element from the array and sets *element with it.
// If the index in out of the bound or the type doesn't match, the function
// fails and sets *element to NULL.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_array_get_const_element_by_index_and_type(
    json_array_t const* array, size_t index, json_type_t type,
    json_array_element_t const** element);

// Gets the element from the array and sets *element with it.
// If the index in out of the bound doesn't match, the function
// fails and sets *element to NULL.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_array_get_element_by_index(json_array_t* array, size_t index,
                                    json_array_element_t** element);

#endif /* !JSON_INTERNAL_GETTERS_INDEX_ARRAY_H_ */
