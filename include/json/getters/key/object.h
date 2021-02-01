#ifndef JSON_GETTERS_KEY_OBJECT_H_
#define JSON_GETTERS_KEY_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

/**
 * @defgroup GettersKeyObject
 * @{
 */

int json_object_get_bool_by_key(json_object_t const* obj, char const* key,
                                bool* value);

int json_object_get_nb_by_key(json_object_t const* obj, char const* key,
                              int* value);

int json_object_get_null_by_key(json_object_t const* obj, char const* key,
                                void const** value);

int json_object_get_string_by_key(json_object_t const* obj, char const* key,
                                  char const** value);

int json_object_get_str_by_key(json_object_t const* obj, char const* key,
                               str_t const** value);

int json_object_get_object_by_key(json_object_t const* obj, char const* key,
                                  json_object_t const** value);

int json_object_get_array_by_key(json_object_t const* obj, char const* key,
                                 json_array_t const** value);

/** @} */

// Check if key correspond with an element of the object.
// The caller should not send a NULL value.
//
// Return:
//   TRUE if it match with an alement
//   FALSE if it haven't match with an element
bool json_object_does_key_exist(json_object_t const* obj, char const* key);


#endif /* !JSON_GETTERS_KEY_OBJECT_H_ */
