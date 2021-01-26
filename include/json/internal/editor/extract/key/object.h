#ifndef JSON_INTERNAL_EDITOR_EXTRACT_KEY_OBJECT_H_
#define JSON_INTERNAL_EDITOR_EXTRACT_KEY_OBJECT_H_

#include <json/internal/error.h>
#include <json/internal/typedef/object.h>

// Extracts the element from the object and sets *element with it. The object's
// element is then set to null type. The ownership of the element's pointer is
// tranfered to the caller.
// f the index is out of the bound or the type doesn't
// match, the function fails and both *element and the array's element are left
// untouched.
//
// Return:
//   Success: JSON_EXIT_SUCCESS
//   Failure: JSON_EXIT_FAILURE
//
int json_object_extract_element_by_key_and_type(json_object_t* obj,
                                                char const* key,
                                                json_type_t type,
                                                json_object_element_t* element);

#endif /* !JSON_INTERNAL_EDITOR_EXTRACT_KEY_OBJECT_H_ */
