#ifndef JSON_GETTERS_INDEX_OBJECT_H_
#define JSON_GETTERS_INDEX_OBJECT_H_

#include <json/error.h>
#include <json/type/object.h>

/**
 * @defgroup GettersIndexObject
 * @{
 */

int json_object_get_bool_by_index(json_object_t const* object, size_t index,
                                  bool* value);

int json_object_get_nb_by_index(json_object_t const* object, size_t index,
                                int* value);

int json_object_get_str_by_index(json_object_t const* object, size_t index,
                                 str_t const** value);

int json_object_get_null_by_index(json_object_t const* object, size_t index,
                                  void const** value);

int json_object_get_object_by_index(json_object_t const* object, size_t index,
                                    json_object_t const** value);

int json_object_get_array_by_index(json_object_t const* object, size_t index,
                                   json_array_t const** value);

/** @} */

#endif /* !JSON_GETTERS_INDEX_OBJECT_H_ */
