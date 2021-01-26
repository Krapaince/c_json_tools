#include <criterion/criterion.h>

#include <json/json.h>

Test(json_array_set_bool_by_index, test_json_array_set_bool_by_index)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_set_bool_by_index(array, 3, true) == JSON_EF);
    cr_assert(json_array_append_bool(array, true) == JSON_ES);
    cr_assert(json_array_append_bool(array, false) == JSON_ES);
    cr_assert(json_array_set_bool_by_index(array, 1, true) == JSON_ES);
    cr_assert(json_array_append_bool(expected, true) == JSON_ES);
    cr_assert(json_array_append_bool(expected, true) == JSON_ES);
    cr_assert(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_set_nb_by_index, test_json_array_set_nb_by_index)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_set_nb_by_index(array, 3, 32) == JSON_EF);
    cr_assert(json_array_append_nb(array, 32) == JSON_ES);
    cr_assert(json_array_append_nb(array, 45) == JSON_ES);
    cr_assert(json_array_set_nb_by_index(array, 0, 56) == JSON_ES);
    cr_assert(json_array_append_nb(expected, 56) == JSON_ES);
    cr_assert(json_array_append_nb(expected, 45) == JSON_ES);
    cr_assert(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_set_str_by_index, test_json_array_set_str_by_index)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();
    char* str = strdup("titi");

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(str != NULL);
    cr_assert(json_array_set_str_by_index(array, 3, "invalud") == JSON_EF);
    cr_assert(json_array_append_str_dup(array, "toto") == JSON_ES);
    cr_assert(json_array_append_str_dup(array, "tutu") == JSON_ES);
    cr_assert(json_array_set_str_by_index(array, 0, str) == JSON_ES);
    cr_assert(json_array_append_str_dup(expected, "titi") == JSON_ES);
    cr_assert(json_array_append_str_dup(expected, "tutu") == JSON_ES);
    cr_assert(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_set_str_dup_by_index, test_json_array_set_str_dup_by_index)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_set_str_by_index(array, 3, "invalud") == JSON_EF);
    cr_assert(json_array_append_str_dup(array, "toto") == JSON_ES);
    cr_assert(json_array_append_str_dup(array, "tutu") == JSON_ES);
    cr_assert(json_array_set_str_dup_by_index(array, 0, "titi") == JSON_ES);
    cr_assert(json_array_append_str_dup(expected, "titi") == JSON_ES);
    cr_assert(json_array_append_str_dup(expected, "tutu") == JSON_ES);
    cr_assert(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_set_null_by_index, test_json_array_set_null_by_index)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(expected != NULL);
    cr_assert(json_array_set_null_by_index(array, 3) == JSON_EF);
    cr_assert(json_array_append_nb(array, 34) == JSON_ES);
    cr_assert(json_array_append_null(array) == JSON_ES);
    cr_assert(json_array_set_null_by_index(array, 0) == JSON_ES);
    cr_assert(json_array_append_null(expected) == JSON_ES);
    cr_assert(json_array_append_null(expected) == JSON_ES);
    cr_assert(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_set_object_by_index, test_json_array_set_object_by_index)
{
    json_array_t* array = json_array_create();
    json_object_t* sub_obj = json_object_create();
    json_array_t* expected = json_array_create();
    json_object_t* sub_obj_expected = json_object_create();

    cr_assert(array != NULL);
    cr_assert(sub_obj != NULL);
    cr_assert(expected != NULL);
    cr_assert(sub_obj_expected != NULL);
    cr_assert(json_array_set_object_by_index(array, 3, sub_obj) == JSON_EF);
    cr_assert(json_array_append_nb(array, 34) == JSON_ES);
    cr_assert(json_array_append_bool(array, false) == JSON_ES);
    cr_assert(json_array_set_object_by_index(array, 1, sub_obj) == JSON_ES);
    cr_assert(json_array_append_nb(expected, 34) == JSON_ES);
    cr_assert(json_array_append_object(expected, sub_obj_expected) == JSON_ES);
    cr_assert(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_set_array_by_index, test_json_array_set_array_by_index)
{
    json_array_t* array = json_array_create();
    json_array_t* sub_array = json_array_create();
    json_array_t* expected = json_array_create();
    json_array_t* sub_array_expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(expected != NULL);
    cr_assert(sub_array_expected != NULL);
    cr_assert(json_array_set_array_by_index(array, 3, sub_array) == JSON_EF);
    cr_assert(json_array_append_nb(array, 34) == JSON_ES);
    cr_assert(json_array_append_bool(array, false) == JSON_ES);
    cr_assert(json_array_set_array_by_index(array, 1, sub_array) == JSON_ES);
    cr_assert(json_array_append_nb(expected, 34) == JSON_ES);
    cr_assert(json_array_append_array(expected, sub_array_expected) == JSON_ES);
    cr_assert(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}
