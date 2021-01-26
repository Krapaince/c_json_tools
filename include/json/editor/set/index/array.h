#ifndef JSON_SET_INDEX_ARRAY_H_
#define JSON_SET_INDEX_ARRAY_H_

#include <json/error.h>
#include <json/type/array.h>

// Sets the value at the index in the array. If the index is out of the bound
// the function success. Otherwise, the function fails, the array if left
// untouched.
//
// Return:
//   Failure: JSON_EF
//   Success: JSON_ES
//
int json_array_set_bool_by_index(json_array_t* array, size_t index, bool value);

// Sets the value at the index in the array. If the index is out of the bound
// the function success. Otherwise, the function fails, the array if left
// untouched.
//
// Return:
//   Failure: JSON_EF
//   Success: JSON_ES
//
int json_array_set_nb_by_index(json_array_t* array, size_t index, int value);

// Sets the value at the index in the array. If the index is out of the bound
// the function success. Otherwise, the function fails, the array if left
// untouched.
// The value is duplicated if the function fails json_errno is set.
//
// Return:
//   Failure: JSON_EF
//   Success: JSON_ES
//
int json_array_set_str_dup_by_index(json_array_t* array, size_t index,
                                    char const* value);

// Sets the value at the index in the array. If the index is out of the bound
// the function success. Otherwise, the function fails, the array if left
// untouched.
// The function takes the pointer ownership.
//
// Return:
//   Failure: JSON_EF
//   Success: JSON_ES
//
int json_array_set_str_by_index(json_array_t* array, size_t index, char* value);

// Sets the value at the index in the array. If the index is out of the bound
// the function success. Otherwise, the function fails, the array if left
// untouched.
//
// Return:
//   Failure: JSON_EF
//   Success: JSON_ES
//
int json_array_set_null_by_index(json_array_t* array, size_t index);

// Sets the value at the index in the array. If the index is out of the bound
// the function success. Otherwise, the function fails, the array if left
// untouched.
// The function takes the pointer ownership.
//
// Return:
//   Failure: JSON_EF
//   Success: JSON_ES
//
int json_array_set_object_by_index(json_array_t* array, size_t index,
                                   json_object_t* value);

// Sets the value at the index in the array. If the index is out of the bound
// the function success. Otherwise, the function fails, the array if left
// untouched.
// The function takes the pointer ownership.
//
// Return:
//   Failure: JSON_EF
//   Success: JSON_ES
//
int json_array_set_array_by_index(json_array_t* array, size_t index,
                                  json_array_t* value);

#endif /* !JSON_SET_INDEX_ARRAY_H_ */
