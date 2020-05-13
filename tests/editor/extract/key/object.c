/*
** EPITECH PROJECT, 2020
** json library
** File description:
** tests editor extract key object
*/

#include <criterion/criterion.h>

#include <json/json.h>

static json_object_t* tests_json_create_object(void)
{
    json_object_t* object = json_object_create();
    json_object_t* sub_object = json_object_create();
    json_array_t* sub_array = json_array_create();

    cr_assert(object != NULL);
    cr_assert(sub_object != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(json_object_append_bool(object, "bool", true) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_nb(object, "nb", 34) == JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_str_dup(object, "str", "toto") ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_null(object, "null") == JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_object(object, "obj", sub_object) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_array(object, "array", sub_array) ==
              JSON_EXIT_SUCCESS);
    return object;
}

static void tests_json_destroy_object(json_object_t* object)
{
    json_object_destroy(object);
}

Test(json_object_extract_bool_by_key,
     tests_json_object_extract_bool_by_key_invalid_key)
{
    json_object_t* object = tests_json_create_object();
    bool value = false;

    cr_expect(json_object_extract_bool_by_key(object, "oui", &value) ==
              JSON_EXIT_FAILURE);
    tests_json_destroy_object(object);
}

Test(json_object_extract_bool_by_key, tests_json_object_extract_bool_by_key)
{
    json_object_t* object = tests_json_create_object();
    bool value = false;

    cr_expect(json_object_extract_bool_by_key(object, "bool", &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == true);
    cr_expect(json_object_extract_bool_by_key(object, "bool", &value) ==
              JSON_EXIT_FAILURE);
    tests_json_destroy_object(object);
}

Test(json_object_extract_nb_by_key, tests_json_object_extract_nb_by_key)
{
    json_object_t* object = tests_json_create_object();
    int value = 0;

    cr_expect(json_object_extract_nb_by_key(object, "nb", &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == 34);
    cr_expect(json_object_extract_nb_by_key(object, "nb", &value) ==
              JSON_EXIT_FAILURE);
    tests_json_destroy_object(object);
}

Test(json_object_extract_string_by_key, tests_json_object_extract_string_by_key)
{
    json_object_t* object = tests_json_create_object();
    char* value = 0;

    cr_expect(json_object_extract_string_by_key(object, "str", &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(value, "toto");
    cr_expect(json_object_extract_string_by_key(object, "str", &value) ==
              JSON_EXIT_FAILURE);
    free(value);
    tests_json_destroy_object(object);
}

Test(json_object_extract_str_by_key, tests_json_object_extract_str_by_key)
{
    json_object_t* object = tests_json_create_object();
    str_t value;

    cr_expect(json_object_extract_str_by_key(object, "str", &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(value.value, "toto");
    cr_expect(json_object_extract_str_by_key(object, "str", &value) ==
              JSON_EXIT_FAILURE);
    free(value.value);
    tests_json_destroy_object(object);
}

Test(json_object_extract_object_by_key, tests_json_object_extract_object_by_key)
{
    json_object_t* object = tests_json_create_object();
    json_object_t* expected = json_object_create();
    json_object_t* value;

    cr_assert(expected != NULL);
    cr_expect(json_object_extract_object_by_key(object, "obj", &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_compare(value, expected));
    cr_expect(json_object_extract_object_by_key(object, "obj", &value) ==
              JSON_EXIT_FAILURE);
    json_object_destroy(value);
    json_object_destroy(expected);
    tests_json_destroy_object(object);
}

Test(json_object_extract_array_by_key, tests_json_object_extract_array_by_key)
{
    json_object_t* object = tests_json_create_object();
    json_array_t* expected = json_array_create();
    json_array_t* value;

    cr_assert(expected != NULL);
    cr_expect(json_object_extract_array_by_key(object, "array", &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_array_compare(value, expected));
    cr_expect(json_object_extract_array_by_key(object, "array", &value) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(value);
    json_array_destroy(expected);
    tests_json_destroy_object(object);
}
