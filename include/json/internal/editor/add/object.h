#ifndef JSON_INTERNAL_EDITOR_ADD_OBJECT_H_
#define JSON_INTERNAL_EDITOR_ADD_OBJECT_H_

#include <json/internal/typedef/object.h>

// Adds an element of type JSON_BOOL at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_bool(json_object_t* obj, char const* key, bool value);

// Adds an element of type JSON_NB at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_nb(json_object_t* obj, char const* key, int value);

// Adds an element of type JSON_STR at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_str_dup(json_object_t* obj, char const* key,
                            char const* value);

// Adds an element of type JSON_STR at the end of the object.
// The function takes the pointer ownership on value.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_str(json_object_t* obj, char const* key, char* value);

// Adds an element of type JSON_NULL at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_null(json_object_t* obj, char const* key);

// Adds an element of type JSON_ARRAY at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_array(json_object_t* obj, char const* key,
                          json_array_t* value);

// Adds an element of type JSON_OBJ at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_object(json_object_t* obj, char const* key,
                           json_object_t* value);

// Adds an element at the end of the object.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_object_add_element(json_object_t* obj, json_object_element_t* element);

#endif /* !JSON_INTERNAL_EDITOR_ADD_OBJECT_H_ */
