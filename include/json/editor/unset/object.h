#ifndef JSON_EDITOR_UNSET_OBJECT_H_
#define JSON_EDITOR_UNSET_OBJECT_H_

#include <json/type/object.h>

/**
 * @defgroup EditorUnsetObjectKey
 * @{
 */

size_t json_object_unset_element_by_key(json_object_t* obj, char const* key);

/** @} */

/**
 * @defgroup EditorUnsetObjectIndex
 * @{
 */

size_t json_object_unset_element_by_index(json_object_t* obj, size_t index);

/** @} */

#endif /* !JSON_EDITOR_UNSET_OBJECT_H_ */
