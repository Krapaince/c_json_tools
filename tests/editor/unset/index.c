#include <criterion/criterion.h>

#include <json/json.h>

Test(json_array_unset_element_by_index,
     test_json_array_unset_element_index_valid)
{
    json_array_t* array = json_array_create();
    json_array_t* expected = json_array_create();

    cr_assert(array != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_ES);
    cr_assert(json_array_append_nb(array, 34) == JSON_ES);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_ES);
    cr_expect(json_array_unset_element_by_index(array, 1) == 1);
    cr_assert(expected != NULL);
    cr_assert(json_array_append_bool(expected, true) == JSON_ES);
    cr_assert(json_array_append_str_dup(expected, "titi") == JSON_ES);
    cr_expect(json_array_compare(array, expected) == true);
    json_array_destroy(array);
    json_array_destroy(expected);
}

Test(json_array_unset_element_by_index,
     test_json_array_unset_element_index_invalid)
{
    json_array_t* array = json_array_create();

    cr_assert(array != NULL);
    cr_assert(json_array_append_bool(array, true) == JSON_ES);
    cr_assert(json_array_append_nb(array, 34) == JSON_ES);
    cr_assert(json_array_append_str_dup(array, "titi") == JSON_ES);
    cr_expect(json_array_unset_element_by_index(array, 4) == 0);
    json_array_destroy(array);
}

Test(json_object_unset_element_by_index,
     test_json_object_unset_element_index_valid)
{
    json_object_t* object = json_object_create();
    json_object_t* expected = json_object_create();

    cr_assert(object != NULL);
    cr_assert(json_object_append_bool(object, "toto", true) == JSON_ES);
    cr_assert(json_object_append_nb(object, "titi", 34) == JSON_ES);
    cr_assert(json_object_append_str_dup(object, "tutu", "titi") == JSON_ES);
    cr_expect(json_object_unset_element_by_index(object, 1) == 1);
    cr_assert(expected != NULL);
    cr_assert(json_object_append_bool(expected, "toto", true) == JSON_ES);
    cr_assert(json_object_append_str_dup(expected, "tutu", "titi") == JSON_ES);
    cr_expect(json_object_compare(object, expected) == true);
    json_object_destroy(object);
    json_object_destroy(expected);
}

Test(json_object_unset_element_by_index,
     test_json_object_unset_element_index_invalid)
{
    json_object_t* object = json_object_create();

    cr_assert(object != NULL);
    cr_assert(json_object_append_bool(object, "titi", true) == JSON_ES);
    cr_expect(json_object_unset_element_by_index(object, 4) == 0);
    json_object_destroy(object);
}
