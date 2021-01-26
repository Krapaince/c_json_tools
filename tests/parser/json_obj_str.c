#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <json/editor/destroy.h>
#include <json/error.h>
#include <json/generator.h>
#include <json/parser.h>
#include <proto.h>

Test(json_object_parse_from_str, test_json_object_parse_from_str_valid)
{
    char* str = get_file_content("tests/file/obj/valid.json");
    json_object_t* obj;
    FILE* expected = fopen("tests/expected/obj/valid.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(str != NULL);
    obj = json_object_parse_from_str(str, NULL);
    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_object_generate_to_file(
                  obj, "tests/output/obj/valid_str.json", &setting) == JSON_ES);
    output = fopen("tests/output/obj/valid_str.json", "r");
    cr_assert(expected != NULL && output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
    free(str);
}

Test(json_object_parse_from_str, test_json_object_parse_from_array_valid_index)
{
    char* str = get_file_content("tests/file/obj/valid.json");
    json_object_t* object;
    size_t len = strlen(str);
    size_t index = 0;

    cr_assert(str != NULL);
    object = json_object_parse_from_str(str, &index);
    cr_assert(object != NULL);
    cr_expect(index = len);
    free(str);
}

Test(json_object_parse_from_str, test_json_object_parse_from_str_invalid_eof)
{
    char* str = get_file_content("tests/file/obj/invalid_eof.json");
    json_object_t* obj;

    cr_assert(str != NULL);
    obj = json_object_parse_from_str(str, NULL);
    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
    free(str);
}
