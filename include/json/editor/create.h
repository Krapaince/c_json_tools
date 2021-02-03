#ifndef JSON_EDITOR_CREATE_H_
#define JSON_EDITOR_CREATE_H_

#include <json/type/array.h>
#include <json/type/object.h>

/**
 * @defgroup EditorCreateArray
 * @{
 */

/**
 * The function creates an empty ``json_array_t``.
 *
 * @return On success the function returns a pointer to a new
 * ``json_array_t``. On failure \b NULL is returned and ``json_errno`` is set to
 * \b JSON_E_SYS_FAILURE.
 *
 */
json_array_t* json_array_create(void);

/** @} */

/**
 * @defgroup EditorCreateObject
 * @{
 */

/**
 * The function creates an empty ``json_object_t``.
 *
 * @return On success the function returns a pointer to a new
 * ``json_object_t``. On failure \b NULL is returned and ``json_errno`` is set
 * to \b JSON_E_SYS_FAILURE.
 *
 */
json_object_t* json_object_create(void);

/** @} */

#endif /* !JSON_EDITOR_CREATE_H_ */
