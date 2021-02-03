#ifndef JSON_EDITOR_COMAPRE_H_
#define JSON_EDITOR_COMAPRE_H_

#include <json/type/array.h>
#include <json/type/object.h>

/**
 * @defgroup EditorCompareObject
 * @{
 */

/**
 * The function compares ``obj1`` with ``obj2``. Equality is defined as follows:
 * - json_object_elements of different type are never equal
 * - json_object_elements of the same primitive type are equal if the
 * c-representation of their value is equal
 * - see json_array_compare for the equality criteria of the array
 * - keys must be in the same order in the two objects
 *
 * @return \b true if the objects are equal, \b false otherewise.
 */
bool json_object_compare(json_object_t const* obj1, json_object_t const* obj2);

/** @} */

/**
 * @defgroup EditorCompareArray
 * @{
 */

/**
 * The function compares ``array1`` with ``array2``. Equality is defined as
 * follows:
 * - json_array_elements of different type are never equal
 * - json_array_elements of the same primitive type are equal if the
 * c-representation of their value is equal
 * - see json_object_compare for the equality criteria of the object
 *
 * @return \b true if the objects are equal, \b false otherewise.
 */
bool json_array_compare(json_array_t const* array1, json_array_t const* array2);

/** @} */

#endif /* !JSON_EDITOR_COMAPRE_H_ */
