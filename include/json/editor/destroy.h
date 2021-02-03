#ifndef JSON_EDITOR_DESTROY_H_
#define JSON_EDITOR_DESTROY_H_

#include <json/type/array.h>
#include <json/type/object.h>

/**
 * @defgroup EditorDestroyObject
 * @{
 */

/**
 * The function releases the allocated resources of ``obj``.
 */
void json_object_destroy(json_object_t* obj);

/** #} */

/**
 * @defgroup EditorDestroyArray
 * @{
 */

/**
 * The function releases the allocated resources of ``array``.
 */
void json_array_destroy(json_array_t* array);

/** #} */

#endif /* !JSON_EDITOR_DESTROY_H_ */
