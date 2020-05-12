/*
** EPITECH PROJECT, 2020
** json library
** File description:
** tests json compare
*/

#include <criterion/criterion.h>

#include <json/json.h>

static json_object_t* test_create_object(void)
{
    json_object_t* object = json_object_create();
    json_object_t* sub_object = json_object_create();
    json_array_t* array = json_array_create();
    char* str = strdup("oui");

    cr_assert(object != NULL);
    cr_assert(sub_object != NULL);
    cr_assert(str != NULL);
    cr_assert(json_object_append_bool(object, "grominet", true) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_nb(object, "titi", -45) == JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_str(sub_object, "oio", str) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_str_dup(sub_object, "oi", "blablou") ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_null(object, "nu") == JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_object(object, "obh", sub_object) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_array(object, "arr", array) ==
              JSON_EXIT_SUCCESS);
    return object;
}

Test(json_object_compare, test_json_object_compare_true)
{
    json_object_t* object = test_create_object();

    cr_assert(object != NULL);
    cr_expect(json_object_compare(object, object) == true);
    json_object_destroy(object);
}

Test(json_object_compare, test_json_object_compare_false)
{
    json_object_t* object = test_create_object();
    json_object_t* object1 = test_create_object();

    cr_assert(object != NULL);
    cr_assert(object1 != NULL);
    cr_assert(json_object_append_str_dup(object1, "cmp", "failure") ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_compare(object, object1) == false);
    json_object_destroy(object);
    json_object_destroy(object1);
}

static json_array_t* test_create_array(void)
{
    json_array_t* array = json_array_create();
    json_array_t* sub_array = json_array_create();
    json_object_t* obj = json_object_create();
    char* str = strdup("titu");

    cr_assert(array != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, -45) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str(array, str) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(array, "toto") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(sub_array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_array(array, sub_array) == JSON_EXIT_SUCCESS);
    cr_assert(json_object_append_nb(obj, "nb", 45) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_object(array, obj) == JSON_EXIT_SUCCESS);
    return array;
}

Test(json_array_compare, test_json_array_compare_true)
{
    json_array_t* array = test_create_array();

    cr_assert(array != NULL);
    cr_expect(json_array_compare(array, array) == true);
    json_array_destroy(array);
}

Test(json_array_compare, test_json_array_compare_false)
{
    json_array_t* array = test_create_array();
    json_array_t* array1 = test_create_array();

    cr_assert(array != NULL);
    cr_assert(array1 != NULL);
    cr_assert(json_array_append_bool(array1, true) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_compare(array, array1) == false);
    json_array_destroy(array);
    json_array_destroy(array1);
}
