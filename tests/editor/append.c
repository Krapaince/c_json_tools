#include <criterion/criterion.h>

#include <json/editor/append.h>
#include <json/editor/create.h>
#include <json/editor/destroy.h>
#include <json/getters/object.h>

Test(json_object_append_bool, test_json_object_append_bool)
{
    json_object_t* obj = json_object_create();
    bool value = false;

    cr_assert(obj != NULL);
    cr_assert(json_object_append_bool(obj, "boolean", true) == JSON_ES);
    cr_assert(json_object_get_bool_by_key(obj, "boolean", &value) == JSON_ES);
    cr_assert(json_object_append_bool(obj, "boolean", true) == JSON_EF);
    cr_expect(json_errno == JSON_E_KEY_ALREADY_EXIST);
    json_object_destroy(obj);
}

Test(json_object_append_nb, test_json_object_append_nb)
{
    json_object_t* obj = json_object_create();
    int value = false;

    cr_assert(obj != NULL);
    cr_assert(json_object_append_nb(obj, "key", 33) == JSON_ES);
    cr_assert(json_object_get_nb_by_key(obj, "key", &value) == JSON_ES);
    cr_assert(json_object_append_nb(obj, "key", 33) == JSON_EF);
    cr_expect(json_errno == JSON_E_KEY_ALREADY_EXIST);
    json_object_destroy(obj);
}

Test(json_object_append_str_dup, test_json_object_append_str_dup)
{
    json_object_t* obj = json_object_create();
    char const* value = false;

    cr_assert(obj != NULL);
    cr_assert(json_object_append_str_dup(obj, "key", "toto") == JSON_ES);
    cr_assert(json_object_get_string_by_key(obj, "key", &value) == JSON_ES);
    cr_assert(json_object_append_str_dup(obj, "key", "titi") == JSON_EF);
    cr_expect(json_errno == JSON_E_KEY_ALREADY_EXIST);
    json_object_destroy(obj);
}

Test(json_object_append_str, test_json_object_append_str)
{
    json_object_t* obj = json_object_create();
    char* str = strdup("toto");
    char const* value = false;

    cr_assert(obj != NULL);
    cr_assert(str != NULL);
    cr_assert(json_object_append_str(obj, "key", str) == JSON_ES);
    cr_assert(json_object_get_string_by_key(obj, "key", &value) == JSON_ES);
    cr_assert(json_object_append_str(obj, "key", "titi") == JSON_EF);
    cr_expect(json_errno == JSON_E_KEY_ALREADY_EXIST);
    json_object_destroy(obj);
}

Test(json_object_append_null, test_json_object_append_null)
{
    json_object_t* obj = json_object_create();
    void const* value = false;

    cr_assert(obj != NULL);
    cr_assert(json_object_append_null(obj, "key") == JSON_ES);
    cr_assert(json_object_get_null_by_key(obj, "key", &value) == JSON_ES);
    cr_assert(json_object_append_null(obj, "key") == JSON_EF);
    cr_expect(json_errno == JSON_E_KEY_ALREADY_EXIST);
    json_object_destroy(obj);
}

Test(json_object_append_array, test_json_object_append_array)
{
    json_object_t* obj = json_object_create();
    json_array_t* sub_array = json_array_create();
    json_array_t const* value = false;

    cr_assert(obj != NULL);
    cr_assert(sub_array != NULL);
    cr_assert(json_object_append_array(obj, "key", sub_array) == JSON_ES);
    cr_assert(json_object_get_array_by_key(obj, "key", &value) == JSON_ES);
    cr_assert(json_object_append_array(obj, "key", sub_array) == JSON_EF);
    cr_expect(json_errno == JSON_E_KEY_ALREADY_EXIST);
    json_object_destroy(obj);
}

Test(json_object_append_object, test_json_object_append_object)
{
    json_object_t* obj = json_object_create();
    json_object_t* sub_obj = json_object_create();
    json_object_t const* value = false;

    cr_assert(obj != NULL);
    cr_assert(sub_obj != NULL);
    cr_assert(json_object_append_object(obj, "key", sub_obj) == JSON_ES);
    cr_assert(json_object_get_object_by_key(obj, "key", &value) == JSON_ES);
    cr_assert(json_object_append_object(obj, "key", sub_obj) == JSON_EF);
    cr_expect(json_errno == JSON_E_KEY_ALREADY_EXIST);
    json_object_destroy(obj);
}
