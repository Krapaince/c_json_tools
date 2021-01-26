#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <json/editor/destroy.h>
#include <json/error.h>
#include <json/generator.h>
#include <json/parser.h>

Test(json_array_parse_from_filepath, test_json_array_parse_from_filepath_valid)
{
    json_array_t* array =
        json_array_parse_from_filepath("tests/file/array/valid.json");
    char const* output_filepath = "tests/output/array/valid_filepath.json";
    FILE* expected = fopen("tests/expected/array/valid.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(array != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_array_generate_to_file(array, output_filepath, &setting) ==
              JSON_ES);
    output = fopen(output_filepath, "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_array_destroy(array);
    fclose(output);
    fclose(expected);
}

Test(json_array_parse_from_filepath,
     test_json_array_parse_from_filepath_invalid_eof)
{
    json_array_t* array =
        json_array_parse_from_filepath("tests/file/array/invalid_eof.json");

    cr_assert(array == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
}

Test(json_array_parse_from_filepath,
     test_json_array_parse_from_filepath_invalid_eof_excess)
{
    json_array_t* array = json_array_parse_from_filepath(
        "tests/file/array/invalid_eof_excess.json");

    cr_assert(array == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
}

Test(json_array_parse_from_filepath,
     test_json_array_parse_from_filepath_synthax)
{
    json_array_t* array =
        json_array_parse_from_filepath("tests/file/array/synthax.json");

    cr_assert(array == NULL);
    cr_assert(json_errno == JSON_E_SYNTHAX);
}

Test(json_array_parse_from_filepath,
     test_json_array_parse_from_filepath_unmatched_quote)
{
    json_array_t* array =
        json_array_parse_from_filepath("tests/file/array/unmatched_quote.json");

    cr_assert(array == NULL);
    cr_assert(json_errno == JSON_E_UNMATCHED_QUOTE);
}
