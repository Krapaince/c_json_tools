#ifndef JSON_EDITOR_EXTRACT_KEY_OBJECT_H_
#define JSON_EDITOR_EXTRACT_KEY_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type.
// If the key is invalid or the value's type doesn't match, the function fails
// and both *value and the object's value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_bool_by_key(json_object_t* obj, char const* key,
                                    bool* value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type.
// If the key is invalid or the value's type doesn't match, the function fails
// and both *value and the object's value are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_nb_by_key(json_object_t* obj, char const* key,
                                  int* value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type. The ownership of the value's pointer is
// tranfered to the caller.
// If the key is invalid or the value's type doesn't
// match, the function fails and both *value and the object's value are left
// untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_string_by_key(json_object_t* obj, char const* key,
                                      char** value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type. The ownership of the value->value's pointer
// is tranfered to the caller.
// If the key is invalid or the value's type doesn't
// match, the function fails and both *value and the object's value are left
// untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_str_by_key(json_object_t* obj, char const* key,
                                   str_t* value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type. The ownership of the value's pointer is
// tranfered to the caller.
// If the key is invalid or the value's type doesn't
// match, the function fails and both *value and the object's value are left
// untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_object_by_key(json_object_t* obj, char const* key,
                                      json_object_t** value);

// Extracts the value from the object and sets *value with it. The object's
// value is then set to null type. The ownership of the value's pointer is
// tranfered to the caller.
// If the key is invalid or the value's type doesn't
// match, the function fails and both *value and the object's value are left
// untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_object_extract_array_by_key(json_object_t* obj, char const* key,
                                     json_array_t** value);

#endif /* !JSON_EDITOR_EXTRACT_KEY_OBJECT_H_ */
