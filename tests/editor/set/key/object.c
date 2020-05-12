/*
** EPITECH PROJECT, 2020
** json library
** File description:
** tests set
*/

#include <criterion/criterion.h>

#include <json/json.h>

Test(json_object_set_bool_by_key, test_json_object_set_bool_by_key)
{
    json_object_t* obj = json_object_create();
    json_object_element_t const* element;
    char const* key = "key";

    cr_assert(obj != NULL);
    cr_assert(json_object_set_bool_by_key(obj, key, true) == JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_bool_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect(element->value.boolean == true);
    cr_assert(json_object_set_bool_by_key(obj, key, false) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_bool_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect(element->value.boolean == false);
    json_object_destroy(obj);
}

Test(json_object_set_nb_by_key, test_json_object_set_nb_by_key)
{
    json_object_t* obj = json_object_create();
    json_object_element_t const* element;
    char const* key = "key";

    cr_assert(obj != NULL);
    cr_assert(json_object_set_nb_by_key(obj, key, 33) == JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_nb_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect(element->value.nb == 33);
    cr_assert(json_object_set_nb_by_key(obj, key, 66) == JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_nb_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect(element->value.nb == 66);
    json_object_destroy(obj);
}

Test(json_object_set_str_by_key, test_json_object_set_str_by_key)
{
    json_object_t* obj = json_object_create();
    json_object_element_t const* element;
    char const* key = "key";
    char* value1 = strdup("value1");
    char* value2 = strdup("value2");

    cr_assert(obj != NULL);
    cr_assert(value1 != NULL && value2 != NULL);
    cr_assert(json_object_set_str_by_key(obj, key, value1) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_str_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(element->value.str.value, "value1");
    cr_assert(json_object_set_str_by_key(obj, key, value2) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_str_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(element->value.str.value, "value2");
    json_object_destroy(obj);
}

Test(json_object_set_str_dup_by_key, test_json_object_set_str_dup_by_key)
{
    json_object_t* obj = json_object_create();
    json_object_element_t const* element;
    char const* key = "key";
    char const* value1 = "value1";
    char const* value2 = "value2";

    cr_assert(obj != NULL);
    cr_assert(json_object_set_str_dup_by_key(obj, key, value1) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_str_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(element->value.str.value, "value1");
    cr_assert(json_object_set_str_dup_by_key(obj, key, value2) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_str_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(element->value.str.value, "value2");
    json_object_destroy(obj);
}

Test(json_object_set_null_by_key, test_json_object_set_null_by_key)
{
    json_object_t* obj = json_object_create();
    json_object_element_t const* element;
    char const* key = "key";

    cr_assert(obj != NULL);
    cr_assert(json_object_set_null_by_key(obj, key) == JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_null_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect(element->value.null == NULL);
    cr_assert(json_object_set_null_by_key(obj, key) == JSON_EXIT_SUCCESS);
    cr_expect(json_object_get_null_element_by_key(obj, key, &element) ==
              JSON_EXIT_SUCCESS);
    cr_expect(element->value.null == NULL);
    json_object_destroy(obj);
}

Test(json_object_set_object_by_key, test_json_object_set_object_by_key)
{
    json_object_t* obj = json_object_create();
    json_object_t* sub_object = json_object_create();
    json_object_t* sub_object2 = json_object_create();
    char const* key = "key";

    cr_assert(obj != NULL);
    cr_assert(sub_object != NULL);
    cr_assert(sub_object2 != NULL);
    cr_assert(json_object_unset_element_by_key(obj, key) == 0);
    cr_assert(json_object_set_object_by_key(obj, key, sub_object) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_unset_element_by_key(obj, key) == 1);
    cr_assert(json_object_set_bool_by_key(obj, key, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_object_set_object_by_key(obj, key, sub_object2) ==
              JSON_EXIT_SUCCESS);
    json_object_destroy(obj);
}

Test(json_object_set_array_by_key, test_json_object_set_array_by_key)
{
    json_object_t* obj = json_object_create();
    json_array_t* sub_array = json_array_create();
    json_array_t* sub_array2 = json_array_create();
    char const* key = "key";

    cr_assert(obj != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(sub_array2 != NULL);
    cr_assert(json_object_unset_element_by_key(obj, key) == 0);
    cr_assert(json_object_set_array_by_key(obj, key, sub_array) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_unset_element_by_key(obj, key) == 1);
    cr_assert(json_object_set_bool_by_key(obj, key, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_object_set_array_by_key(obj, key, sub_array2) ==
              JSON_EXIT_SUCCESS);
    json_object_destroy(obj);
}
