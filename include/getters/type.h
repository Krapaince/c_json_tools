/*
** EPITECH PROJECT, 2020
** json library
** File description:
** getters type
*/

#ifndef JSON_GETTERS_TYPE_H_
#define JSON_GETTERS_TYPE_H_

#include <typedef/array.h>
#include <typedef/object.h>

bool json_does_element_is_type(json_type_t element_type, json_type_t type);

bool json_object_does_element_is_a_bool(json_object_element_t const* element);
bool json_object_does_element_is_a_nb(json_object_element_t const* element);
bool json_object_does_element_is_a_str(json_object_element_t const* element);
bool json_object_does_element_is_a_null(json_object_element_t const* element);
bool json_object_does_element_is_an_array(json_object_element_t const* element);
bool json_object_does_element_is_an_object(
    json_object_element_t const* element);
bool json_object_does_element_is_type(json_object_element_t const* element,
                                      json_type_t type);

bool json_array_does_element_is_a_bool(json_array_element_t const* element);
bool json_array_does_element_is_a_nb(json_array_element_t const* element);
bool json_array_does_element_is_a_str(json_array_element_t const* element);
bool json_array_does_element_is_a_null(json_array_element_t const* element);
bool json_array_does_element_is_an_array(json_array_element_t const* element);
bool json_array_does_element_is_an_object(json_array_element_t const* element);
bool json_array_does_element_is_type(json_array_element_t const* element,
                                     json_type_t type);

#endif /* !JSON_GETTERS_TYPE_H_ */
