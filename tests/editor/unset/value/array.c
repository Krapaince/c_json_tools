/*
** EPITECH PROJECT, 2020
** json library
** File description:
** tests unset basic type
*/

#include <criterion/criterion.h>

#include <json/json.h>

Test(json_array_unset_elements_by_value_bool,
     tests_json_array_unset_elements_by_value_bool)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(array, false) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(expected, false) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_unset_elements_by_value_bool(array, true) == 2);
    cr_expect(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_unset_elements_by_value_nb,
     tests_json_array_unset_elements_by_value_nb)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_append_nb(array, 34) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 35) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 36) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(expected, 34) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_unset_elements_by_value_nb(array, 35) == 1);
    cr_expect(json_array_unset_elements_by_value_nb(array, 36) == 1);
    cr_expect(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_unset_elements_by_value_str,
     tests_json_array_unset_elements_by_value_str)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();
    str_t const* str;

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(array, "toto") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(array, "toto") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(expected, "toto") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(expected, "toto") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_get_str_by_index(array, 2, &str) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_unset_elements_by_value_str(array, str) == 2);
    cr_expect(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_unset_elements_by_null, tests_json_array_unset_elements_by_null)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 35) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(expected, 35) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_unset_elements_by_null(array) == 2);
    cr_expect(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_unset_elements_by_value_object,
     tests_json_array_unset_elements_by_value_object)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();
    json_object_t* sub_obj = json_object_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(sub_obj != NULL);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_object(array, sub_obj) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 34) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_null(expected) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(expected, 34) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_unset_elements_by_value_object(array, sub_obj) == 1);
    cr_expect(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_unset_elements_by_value_array,
     tests_json_array_unset_elements_by_value_array)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();
    json_array_t* sub_array = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_array(array, sub_array) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 34) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_null(expected) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(expected, 34) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_unset_elements_by_value_array(array, sub_array) == 1);
    cr_expect(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}
