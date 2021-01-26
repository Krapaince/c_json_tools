#include <criterion/criterion.h>

#include <json/json.h>

static json_array_t* tests_json_array_create(void)
{
    json_array_t* array = json_array_create();
    json_array_t* sub_array = json_array_create();
    json_object_t* sub_object = json_object_create();

    cr_assert(array != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(sub_object != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 34) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(array, "toto") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_object(array, sub_object) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_array(array, sub_array) == JSON_EXIT_SUCCESS);
    return array;
}

static void tests_json_array_destroy(json_array_t* array)
{
    json_array_destroy(array);
}

Test(json_array_extract_bool_by_index,
     test_json_array_extract_bool_by_index_out_of_bounds)
{
    json_array_t* array = tests_json_array_create();
    bool value = false;

    cr_expect(json_array_extract_bool_by_index(array, 45, &value) ==
              JSON_EXIT_FAILURE);
    tests_json_array_destroy(array);
}

Test(json_array_extract_bool_by_index, test_json_array_extract_bool_by_index)
{
    json_array_t* array = tests_json_array_create();
    bool value = false;

    cr_expect(json_array_extract_bool_by_index(array, 0, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == true);
    cr_expect(json_array_extract_bool_by_index(array, 0, &value) ==
              JSON_EXIT_FAILURE);
    tests_json_array_destroy(array);
}

Test(json_array_extract_nb_by_index, test_json_array_extract_nb_by_index)
{
    json_array_t* array = tests_json_array_create();
    int value = 0;

    cr_expect(json_array_extract_nb_by_index(array, 1, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(value == 34);
    cr_expect(json_array_extract_nb_by_index(array, 1, &value) ==
              JSON_EXIT_FAILURE);
    tests_json_array_destroy(array);
}

Test(json_array_extract_string_by_index,
     test_json_array_extract_string_by_index)
{
    json_array_t* array = tests_json_array_create();
    char* value = NULL;

    cr_expect(json_array_extract_string_by_index(array, 2, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(value, "toto");
    cr_expect(json_array_extract_string_by_index(array, 2, &value) ==
              JSON_EXIT_FAILURE);
    free(value);
    tests_json_array_destroy(array);
}

Test(json_array_extract_str_by_index, test_json_array_extract_string_by_index)
{
    json_array_t* array = tests_json_array_create();
    str_t value;

    cr_expect(json_array_extract_str_by_index(array, 2, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect_str_eq(value.value, "toto");
    cr_expect(json_array_extract_str_by_index(array, 2, &value) ==
              JSON_EXIT_FAILURE);
    free(value.value);
    tests_json_array_destroy(array);
}

Test(json_array_extract_object_by_index,
     test_json_array_extract_object_by_index)
{
    json_array_t* array = tests_json_array_create();
    json_object_t* value;
    json_object_t* expected = json_object_create();

    cr_assert(expected != NULL);
    cr_expect(json_array_extract_object_by_index(array, 4, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_compare(value, expected));
    cr_expect(json_array_extract_object_by_index(array, 4, &value) ==
              JSON_EXIT_FAILURE);
    json_object_destroy(value);
    json_object_destroy(expected);
    tests_json_array_destroy(array);
}

Test(json_array_extract_array_by_index, test_json_array_extract_object_by_index)
{
    json_array_t* array = tests_json_array_create();
    json_array_t* value;
    json_array_t* expected = json_array_create();

    cr_assert(expected != NULL);
    cr_expect(json_array_extract_array_by_index(array, 5, &value) ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_array_compare(value, expected));
    cr_expect(json_array_extract_array_by_index(array, 5, &value) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(value);
    json_array_destroy(expected);
    tests_json_array_destroy(array);
}
