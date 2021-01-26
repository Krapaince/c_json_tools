#include <criterion/criterion.h>

#include <json/json.h>

Test(json_object_get_bool_by_index, test_json_array_get_bool_by_index)
{
    json_object_t* object = json_object_create();
    bool value = false;

    cr_assert(object != NULL);
    cr_assert(json_object_append_bool(object, "bool", true) == JSON_ES);
    cr_assert(json_object_append_nb(object, "nb", 34) == JSON_ES);
    cr_assert(json_object_get_bool_by_index(object, 0, &value) == JSON_ES);
    cr_expect(value == true);
    cr_assert(json_object_get_bool_by_index(object, 1, &value) == JSON_EF);
    json_object_destroy(object);
}

Test(json_object_get_nb_by_index, test_json_array_get_nb_by_index)
{
    json_object_t* object = json_object_create();
    int value = false;

    cr_assert(object != NULL);
    cr_assert(json_object_append_bool(object, "bool", true) == JSON_ES);
    cr_assert(json_object_append_nb(object, "nb", 34) == JSON_ES);
    cr_assert(json_object_get_nb_by_index(object, 0, &value) == JSON_EF);
    cr_assert(json_object_get_nb_by_index(object, 1, &value) == JSON_ES);
    cr_expect(value == 34);
    json_object_destroy(object);
}

Test(json_object_get_str_by_index, test_json_array_get_str_by_index)
{
    json_object_t* object = json_object_create();
    str_t const* value = NULL;

    cr_assert(object != NULL);
    cr_assert(json_object_append_str_dup(object, "str", "value") == JSON_ES);
    cr_assert(json_object_append_nb(object, "nb", 34) == JSON_ES);
    cr_assert(json_object_get_str_by_index(object, 0, &value) == JSON_ES);
    cr_assert(json_object_get_str_by_index(object, 1, &value) == JSON_EF);
    cr_expect_str_eq(value->value, "value");
    json_object_destroy(object);
}

Test(json_object_get_null_by_index, test_json_array_get_null_by_index)
{
    json_object_t* object = json_object_create();
    void const* value = NULL;

    cr_assert(object != NULL);
    cr_assert(json_object_append_null(object, "null") == JSON_ES);
    cr_assert(json_object_append_nb(object, "nb", 34) == JSON_ES);
    cr_assert(json_object_get_null_by_index(object, 0, &value) == JSON_ES);
    cr_assert(json_object_get_null_by_index(object, 1, &value) == JSON_EF);
    cr_expect(value == NULL);
    json_object_destroy(object);
}

Test(json_object_get_object_by_index, test_json_array_get_object_by_index)
{
    json_object_t* object = json_object_create();
    json_object_t* sub_object = json_object_create();
    json_object_t const* value = NULL;

    cr_assert(object != NULL);
    cr_assert(sub_object != NULL);
    cr_assert(json_object_append_object(object, "obj", sub_object) == JSON_ES);
    cr_assert(json_object_append_nb(object, "nb", 34) == JSON_ES);
    cr_assert(json_object_get_object_by_index(object, 0, &value) == JSON_ES);
    cr_assert(json_object_get_object_by_index(object, 1, &value) == JSON_EF);
    cr_expect(json_object_compare(sub_object, value) == true);
    json_object_destroy(object);
}

Test(json_object_get_array_by_index, test_json_array_get_array_by_index)
{
    json_object_t* object = json_object_create();
    json_array_t* sub_array = json_array_create();
    json_array_t const* value = NULL;

    cr_assert(object != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(json_object_append_array(object, "obj", sub_array) == JSON_ES);
    cr_assert(json_object_append_nb(object, "nb", 34) == JSON_ES);
    cr_assert(json_object_get_array_by_index(object, 0, &value) == JSON_ES);
    cr_assert(json_object_get_array_by_index(object, 1, &value) == JSON_EF);
    cr_expect(json_array_compare(sub_array, value) == true);
    json_object_destroy(object);
}
