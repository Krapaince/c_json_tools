#ifndef JSON_INTERNAL_EDITOR_EXTRACT_INDEX_ARRAY_H_
#define JSON_INTERNAL_EDITOR_EXTRACT_INDEX_ARRAY_H_

#include <json/internal/typedef/array.h>

// Extracts the element from the array and sets *element with it. The array's
// element is then set to null type. The ownership of the element's pointer is
// tranfered to the caller.
// If the index is out of the bound or the element's
// type at index doesn't match, the function fails and both *element and the
// array's element are left untouched.
//
// Return:
//   Success: JSON_ES
//   Failure: JSON_EF
//
int json_array_extract_element_by_index_and_type(json_array_t* array,
                                                 size_t index, json_type_t type,
                                                 json_array_element_t* element);

#endif /* !JSON_INTERNAL_EDITOR_EXTRACT_INDEX_ARRAY_H_ */
