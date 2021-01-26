#ifndef JSON_INTERNAL_EDITOR_COMPARE_TYPE_H_
#define JSON_INTERNAL_EDITOR_COMPARE_TYPE_H_

#include <json/internal/typedef/array.h>
#include <json/internal/typedef/object.h>
#include <json/internal/typedef/type.h>

// Compares element_type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_compare_element_type(json_type_t element_type, json_type_t type);

// Compares element type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_object_compare_element_type(json_object_element_t const* element,
                                      json_type_t type);

// Compares element type and type
// Return:
//   true if the type are identical
//   false otherwise
bool json_array_compare_element_type(json_array_element_t const* element,
                                     json_type_t type);

#endif /* !JSON_INTERNAL_EDITOR_COMAPRE_TYPE_H_ */
