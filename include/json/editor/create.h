/*
** EPITECH PROJECT, 2020
** json library
** File description:
** json create
*/

#ifndef JSON_EXPORT_EDITOR_CREATE_H_
#define JSON_EXPORT_EDITOR_CREATE_H_

#include <json/type/array.h>
#include <json/type/object.h>

// json_array_create allocates a new json_array_t
//
// Return:
//   Failure: NULL
//   Success: A pointer to a new json_array_t
//
// In case of failure, json_errno is set to SYS_FAILURE.
//
json_array_t* json_array_create(void);

// json_create_object allocates a new json_object_t
//
// Return:
//   Failure: NULL
//   Success: A pointer to a new json_object_t
//
// In case of failure, json_errno is set to SYS_FAILURE.
//
json_object_t* json_object_create(void);

#endif /* !JSON_EXPORT_EDITOR_CREATE_H_ */
