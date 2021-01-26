#ifndef JSON_GETTERS_VALUE_ARRAY_H_
#define JSON_GETTERS_VALUE_ARRAY_H_

#include <json/error.h>
#include <json/type/array.h>

// Gets the index by searching through the array for value and sets
// *index with the first found value index if one. The search starts from the
// begin of the array. If the vaue doesn't match any in array the function fails
// and index is left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_bool_value(json_array_t const* array, bool value,
                                       size_t* index);

// Gets the index by searching through the array for value and sets
// *index with the first found value index if one. The search starts from the
// begin of the array. If the vaue doesn't match any in array the function fails
// and index is left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_nb_value(json_array_t const* array, int value,
                                     size_t* index);

// Gets the index by searching through the array for value and sets
// *index with the first found value index if one. The search starts from the
// begin of the array. If the vaue doesn't match any in array the function fails
// and index is left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_string_value(json_array_t const* array, char* value,
                                         size_t* index);

// Gets the index by searching through the array for value and sets
// *index with the first found value index if one. The search starts from the
// begin of the array. If the vaue doesn't match any in array the function fails
// and index is left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_str_value(json_array_t const* array, str_t* value,
                                      size_t* index);

// Gets the index by searching through the array for value and sets
// *index with the first found value index if one. The search starts from the
// begin of the array. If the vaue doesn't match any in array the function fails
// and index is left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_null_value(json_array_t const* array,
                                       size_t* index);

// Gets the index by searching through the array for value and sets
// *index with the first found value index if one. The search starts from the
// begin of the array. If the vaue doesn't match any in array the function fails
// and index is left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_object_value(json_array_t const* array,
                                         json_object_t* value, size_t* index);

// Gets the index by searching through the array for value and sets
// *index with the first found value index if one. The search starts from the
// begin of the array. If the vaue doesn't match any in array the function fails
// and index is left untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_array_get_index_by_array_value(json_array_t const* array,
                                        json_array_t* value, size_t* index);

#endif /* !JSON_GETTERS_VALUE_ARRAY_H_ */
