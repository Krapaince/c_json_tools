#include <criterion/criterion.h>

#include <json/editor/destroy.h>
#include <json/getters/object.h>
#include <json/internal/parser/object.h>
#include <json/parser.h>

Test(json_object_get_bool_value_by_key, test_json_object_get_bool_value_by_key)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    bool value = false;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_bool_by_key(obj, "bool_true", &value) == JSON_ES);
    cr_expect(value == true);
    json_object_destroy(obj);
}

Test(json_object_get_bool_value_by_key,
     test_json_object_get_bool_value_by_key_invalid_key)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    bool value = false;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_bool_by_key(obj, "bool_true_invalid", &value) ==
              JSON_EF);
    json_object_destroy(obj);
}

Test(json_object_get_bool_value_by_key,
     test_json_object_get_bool_value_by_key_invalid_type)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    bool value = false;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_bool_by_key(obj, "array", &value) == JSON_EF);
    json_object_destroy(obj);
}

Test(json_object_get_array_value_by_key,
     test_json_object_get_array_value_by_key)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    json_array_t const* value = NULL;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_array_by_key(obj, "array", &value) == JSON_ES);
    cr_expect(value != NULL);
    json_object_destroy(obj);
}

Test(json_object_get_nb_value_by_key, test_json_object_get_nb_value_by_key)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    int value = 0;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_nb_by_key(obj, "nbr", &value) == JSON_ES);
    cr_expect(value == 34);
    json_object_destroy(obj);
}

Test(json_object_get_null_value_by_key, test_json_object_get_null_value_by_key)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    void const* value = NULL;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_null_by_key(obj, "null", &value) == JSON_ES);
    cr_expect(value == NULL);
    json_object_destroy(obj);
}

Test(json_object_get_object_value_by_key,
     test_json_object_get_object_value_by_key)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid_hard.json");
    json_object_t const* value = NULL;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_object_by_key(obj, "obj", &value) == JSON_ES);
    cr_expect(value != NULL);
    json_object_destroy(obj);
}

Test(json_object_get_str_value_by_key, test_json_object_get_str_value_by_key)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid_hard.json");
    char const* value = NULL;

    cr_assert(obj != NULL);
    cr_expect(json_object_get_string_by_key(obj, "str", &value) == JSON_ES);
    cr_expect_str_eq(value, "str");
    json_object_destroy(obj);
}
