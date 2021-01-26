#include <criterion/criterion.h>

#include <json/json.h>

Test(json_object_unset_element_by_key, test_json_unset_element_by_key)
{
    json_object_t* obj = json_object_create();

    cr_assert(obj != NULL);
    cr_assert(json_object_set_bool_by_key(obj, "toto", true) ==
              JSON_EXIT_SUCCESS);
    cr_assert(json_object_set_str_dup_by_key(obj, "roro", "string") ==
              JSON_EXIT_SUCCESS);
    cr_expect(json_object_unset_element_by_key(obj, "toto") == 1);
    cr_expect(json_object_unset_element_by_key(obj, "toto") == 0);
    cr_expect(json_object_does_key_exist(obj, "toto") == false);
    cr_expect(json_object_does_key_exist(obj, "roro") == true);
    json_object_destroy(obj);
}
