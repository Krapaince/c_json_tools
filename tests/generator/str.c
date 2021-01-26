#include <criterion/criterion.h>
#include <string.h>

#include <json/json.h>
#include <proto.h>

Test(json_array_generate_to_string, test_json_array_generate_to_string)
{
    char* filepath = "tests/file/array/valid_long.json";
    char* expected;
    char* str;
    generator_setting_t setting = {SPACE, 2};
    json_array_t* array = json_array_parse_from_filepath(filepath);

    cr_assert(array != NULL);
    expected = get_file_content(filepath);
    cr_assert(json_array_generate_to_string(array, &setting, &str) == JSON_ES);
    cr_expect(strcmp(str, expected) == 0);
    json_array_destroy(array);
    free(expected);
    free(str);
}

Test(json_object_generate_to_string, test_json_object_generate_to_string)
{
    char* filepath = "tests/file/obj/valid_long.json";
    char* expected;
    char* str;
    generator_setting_t setting = {SPACE, 2};
    json_object_t* object = json_object_parse_from_filepath(filepath);

    cr_assert(object != NULL);
    expected = get_file_content(filepath);
    cr_assert(json_object_generate_to_string(object, &setting, &str) ==
              JSON_ES);
    cr_expect(strcmp(str, expected) == 0);
    json_object_destroy(object);
    free(expected);
    free(str);
}
