#include <criterion/criterion.h>

#include <json/json.h>

Test(json_array_get_bool_by_index, test_json_array_get_bool_by_index)
{
    json_array_t* array = json_array_create();
    bool value = false;

    cr_assert(array != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 45) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(array, false) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_bool_by_index(array, 0, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == true);
    cr_expect(json_array_get_bool_by_index(array, 1, &value) ==
              JSON_EXIT_FAILURE);
    cr_expect(json_array_get_bool_by_index(array, 2, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == false);
    json_array_destroy(array);
}

Test(json_array_get_nb_by_index, test_json_array_get_nb_by_index)
{
    json_array_t* array = json_array_create();
    int value = 0;

    cr_assert(array != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 45) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(array, false) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_nb_by_index(array, 0, &value) ==
              JSON_EXIT_FAILURE);
    cr_expect(json_array_get_nb_by_index(array, 1, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == 45);
    json_array_destroy(array);
}

Test(json_array_get_str_by_index, test_json_array_get_str_by_index)
{
    json_array_t* array = json_array_create();
    str_t const* value = 0;

    cr_assert(array != NULL);
    cr_assert(json_array_append_str_dup(array, "toto") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 45) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_str_by_index(array, 0, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(value->value, "toto");
    cr_expect(value->len == 4);
    cr_expect(json_array_get_str_by_index(array, 1, &value) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(array);
}

Test(json_array_get_null_by_index, test_json_array_get_null_by_index)
{
    json_array_t* array = json_array_create();
    void const* value = NULL;

    cr_assert(array != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_null_by_index(array, 0, &value) ==
              JSON_EXIT_FAILURE);
    cr_expect(json_array_get_null_by_index(array, 1, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == NULL);
    json_array_destroy(array);
}

Test(json_array_get_object_by_index, test_json_array_get_object_by_index)
{
    json_array_t* array = json_array_create();
    json_object_t* object = json_object_create();
    json_object_t const* value = 0;

    cr_assert(array != NULL);
    cr_assert(object != NULL);
    cr_assert(json_array_append_object(array, object) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 45) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_object_by_index(array, 0, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_compare(object, value) == true);
    cr_expect(json_array_get_object_by_index(array, 1, &value) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(array);
}

Test(json_array_get_array_by_index, test_json_array_get_array_by_index)
{
    json_array_t* array = json_array_create();
    json_array_t* sub_array = json_array_create();
    json_array_t const* value = 0;

    cr_assert(array != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(json_array_append_nb(array, 45) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_array(array, sub_array) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_array_by_index(array, 0, &value) ==
              JSON_EXIT_FAILURE);
    cr_expect(json_array_get_array_by_index(array, 1, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_array_compare(sub_array, value) == true);
    json_array_destroy(array);
}
