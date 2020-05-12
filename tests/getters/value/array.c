/*
** EPITECH PROJECT, 2020
** json library
** File description:
** tests getters value array
*/

#include <criterion/criterion.h>

#include <json/json.h>

Test(json_array_get_index_by_bool_value, test_array_get_index_by_bool_value)
{
    json_array_t* array = json_array_create();
    size_t index = 532;

    cr_assert(array != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_bool(array, true) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_index_by_bool_value(array, true, &index) ==
              JSON_EXIT_SUCCESS);
    cr_expect(index == 0);
    cr_expect(json_array_get_index_by_bool_value(array, false, &index) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(array);
}

Test(json_array_get_index_by_nb_value, test_array_get_index_by_nb_value)
{
    json_array_t* array = json_array_create();
    size_t index = 532;

    cr_assert(array != NULL);
    cr_assert(json_array_append_nb(array, -34) == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_nb(array, 34) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_index_by_nb_value(array, 34, &index) ==
              JSON_EXIT_SUCCESS);
    cr_expect(index == 1);
    cr_expect(json_array_get_index_by_bool_value(array, -234, &index) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(array);
}

Test(json_array_get_index_by_string_value, test_array_get_index_by_string_value)
{
    json_array_t* array = json_array_create();
    size_t index = 532;
    char* string = "erro";

    cr_assert(array != NULL);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(array, "erro") == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_index_by_string_value(array, string, &index) ==
              JSON_EXIT_SUCCESS);
    cr_expect(index == 1);
    string = "titie";
    cr_expect(json_array_get_index_by_string_value(array, string, &index) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(array);
}

Test(json_array_get_index_by_str_value, test_array_get_index_by_str_value)
{
    json_array_t* array = json_array_create();
    size_t index = 532;
    str_t str = {.value = "erro", .len = 4};

    cr_assert(array != NULL);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_str_dup(array, "erro") == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_index_by_str_value(array, &str, &index) ==
              JSON_EXIT_SUCCESS);
    cr_expect(index == 1);
    str.value = "titie";
    cr_expect(json_array_get_index_by_str_value(array, &str, &index) ==
              JSON_EXIT_FAILURE);
    json_array_destroy(array);
}

Test(json_array_get_index_by_null_value, test_array_get_index_by_null_value)
{
    json_array_t* array = json_array_create();
    size_t index = 532;

    cr_assert(array != NULL);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_null(array) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_index_by_null_value(array, &index) ==
              JSON_EXIT_SUCCESS);
    cr_expect(index == 1);
    json_array_destroy(array);
}

Test(json_array_get_index_by_object_value, test_array_get_index_by_object_value)
{
    json_array_t* array = json_array_create();
    json_object_t* sub_object = json_object_create();
    size_t index = 532;

    cr_assert(array != NULL);
    cr_assert(sub_object != NULL);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_object(array, sub_object) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_index_by_object_value(array, sub_object, &index) ==
              JSON_EXIT_SUCCESS);
    cr_expect(index == 1);
    json_array_destroy(array);
}

Test(json_array_get_index_by_array_value, test_array_get_index_by_array_value)
{
    json_array_t* array = json_array_create();
    json_array_t* sub_array = json_array_create();
    size_t index = 532;

    cr_assert(array != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_EXIT_SUCCESS);
    cr_assert(json_array_append_array(array, sub_array) == JSON_EXIT_SUCCESS);
    cr_expect(json_array_get_index_by_array_value(array, sub_array, &index) ==
              JSON_EXIT_SUCCESS);
    cr_expect(index == 1);
    json_array_destroy(array);
}
