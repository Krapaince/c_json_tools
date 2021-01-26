#ifndef JSON_EXTRACT_INDEX_OBJECT_H_
#define JSON_EXTRACT_INDEX_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type.
// If the index is out of the bound or the
// value's type at index doesn't match, the function fails and both *value and
// the array's value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_bool_by_index(json_object_t* object, size_t index,
                                      bool* value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type.
// If the index is out of the bound or the
// value's type at index doesn't match, the function fails and both *value and
// the array's value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_nb_by_index(json_object_t* object, size_t index,
                                    int* value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type. The ownership of the value's pointer is
// tranfered to the caller.
// If the index is out of the bound or the value's type
// at index doesn't match, the function fails and both *value and the array's
// value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_string_by_index(json_object_t* object, size_t index,
                                        char** value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type.
// The ownership of the value->value's pointer is
// tranfered to the caller. If the index is out of the bound or the value's type
// at index doesn't match, the function fails and both *value and the array's
// value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_str_by_index(json_object_t* object, size_t index,
                                     str_t* value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type. The ownership of the value's pointer is
// tranfered to the caller.
// If the index is out of the bound or the value's type
// at index doesn't match, the function fails and both *value and the array's
// value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_object_by_index(json_object_t* object, size_t index,
                                        json_object_t** value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type. The ownership of the value's pointer is
// tranfered to the caller.
// If the index is out of the bound or the value's type
// at index doesn't match, the function fails and both *value and the array's
// value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_array_by_index(json_object_t* object, size_t index,
                                       json_array_t** value);

#endif /* !JSON_EXTRACT_INDEX_OBJECT_H_ */
