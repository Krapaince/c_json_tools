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

Test(json_array_parse_from_str, test_json_parse_araay_from_array_valid)
{
    char* str = get_file_content("tests/file/array/valid.json");
    json_array_t* array;
    FILE* expected = fopen("tests/expected/array/valid.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(str != NULL);
    array = json_array_parse_from_str(str, NULL);
    cr_assert(array != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_array_generate_to_file(array,
                                          "tests/output/array/valid_str.json",
                                          &setting) == JSON_ES);
    output = fopen("tests/output/array/valid_str.json", "r");
    cr_assert(expected != NULL && output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_array_destroy(array);
    fclose(output);
    fclose(expected);
    free(str);
}

Test(json_array_parse_from_str, test_json_parse_araay_from_array_valid_index)
{
    char* str = get_file_content("tests/file/array/valid.json");
    json_array_t* array;
    size_t len = strlen(str);
    size_t index = 0;

    cr_assert(str != NULL);
    array = json_array_parse_from_str(str, &index);
    cr_assert(array != NULL);
    cr_expect(index = len);
    free(str);
}

Test(json_array_parse_from_str, test_json_array_parse_from_str_invalid_eof)
{
    char* str = get_file_content("tests/file/array/invalid_eof.json");
    json_array_t* array;

    cr_assert(str != NULL);
    array = json_array_parse_from_str(str, NULL);
    cr_assert(array == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
    free(str);
}
