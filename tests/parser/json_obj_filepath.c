/*
** EPITECH PROJECT, 2020
** json library
** File description:
** tests parser and generator via obj filepath
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <json/editor/destroy.h>
#include <json/error.h>
#include <json/generator.h>
#include <json/parser.h>

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_valid)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    char const* output_filepath = "tests/output/obj/valid_filepath.json";
    FILE* expected = fopen("tests/expected/obj/valid.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_object_generate_to_file(obj, output_filepath, &setting) ==
              JSON_EXIT_SUCCESS);
    output = fopen(output_filepath, "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_valid_hard)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid_hard.json");
    char const* output_filepath = "tests/output/obj/valid_hard_filepath.json";
    FILE* expected = fopen("tests/expected/obj/valid_hard.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_object_generate_to_file(obj, output_filepath, &setting) ==
              JSON_EXIT_SUCCESS);
    output = fopen(output_filepath, "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_escape_char)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/escape_char.json");
    char const* output_filepath = "tests/output/obj/escape_char.json";
    FILE* expected = fopen("tests/expected/obj/escape_char.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_object_generate_to_file(obj, output_filepath, &setting) ==
              JSON_EXIT_SUCCESS);
    output = fopen(output_filepath, "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_long_str)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/long_str.json");
    char const* output_filepath = "tests/output/obj/long_str.json";
    FILE* expected = fopen("tests/expected/obj/long_str.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_object_generate_to_file(obj, output_filepath, &setting) ==
              JSON_EXIT_SUCCESS);
    output = fopen(output_filepath, "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_with_default_formatting)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    char const* output_filepath =
        "tests/output/obj/valid_default_formatting.json";
    FILE* expected =
        fopen("tests/expected/obj/valid_default_formatting.json", "r");
    FILE* output;

    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_object_generate_to_file(obj, output_filepath, NULL) ==
              JSON_EXIT_SUCCESS);
    output = fopen(output_filepath, "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_valid_without_formatting)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/valid.json");
    char const* output_filepath =
        "tests/output/obj/valid_filepath_format_disable.json";
    FILE* expected = fopen("tests/expected/obj/valid_format_disable.json", "r");
    FILE* output;
    generator_setting_t setting = {DISABLE, 2};

    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_object_generate_to_file(obj, output_filepath, &setting) ==
              JSON_EXIT_SUCCESS);
    output = fopen(output_filepath, "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_invalid_eof)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/invalid_eof.json");

    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_invalid_eof_excess)
{
    json_object_t* obj = json_object_parse_from_filepath(
        "tests/file/obj/invalid_eof_excess.json");

    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_key_duplicated)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/key_duplicated.json");

    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_KEY_DUPLICATED);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_synthax)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/synthax.json");

    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_SYNTHAX);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_unknow_type)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/unknow_type.json");

    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_UNKNOW_TYPE);
}

Test(json_object_parse_from_filepath,
     test_json_object_parse_from_filepath_unmathed_quote)
{
    json_object_t* obj =
        json_object_parse_from_filepath("tests/file/obj/unmatched_quote.json");

    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_UNMATCHED_QUOTE);
}
