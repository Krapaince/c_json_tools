#ifndef JSON_EDITOR_DESTROY_H_
#define JSON_EDITOR_DESTROY_H_

#include <json/type/array.h>
#include <json/type/object.h>

// Frees the memory allocated for the json_object_t structure.
void json_object_destroy(json_object_t* obj);

// Frees the memory allocated for the json_array_t structure.
void json_array_destroy(json_array_t* array);

#endif /* !JSON_EDITOR_DESTROY_H_ */
