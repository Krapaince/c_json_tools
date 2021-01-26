#ifndef JSON_INTERNAL_EDITOR_KEY_H_
#define JSON_INTERNAL_EDITOR_KEY_H_

#include <json/internal/typedef/object.h>

// Assigns to the element the key (duplicate key)
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_assign_key_to_element(json_object_element_t* element, char const* key);

// Check if the key isn't in the object. If the key isn't in the object, the
// function assigns to element the key
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
int json_assign_key_to_element_safe(json_object_t const* obj,
                                    json_object_element_t* element,
                                    char const* key);
#endif /* !JSON_INTERNAL_EDITOR_KEY_H_ */
