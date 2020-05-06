/*
** EPITECH PROJECT, 2020
** json library
** File description:
** tests parser and generator
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
#include <proto.h>

Test(json_parse_obj_from_str, test_json_parse_obj_from_str_valid)
{
    char* str = get_file_content("tests/file/obj/valid.json");
    json_object_t* obj;
    FILE* expected = fopen("tests/expected/obj/valid.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(str != NULL);
    obj = json_parse_obj_from_str(str);
    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_generate_obj_to_file(obj, "tests/output/obj/valid_str.json",
                                        &setting) == JSON_EXIT_SUCCESS);
    output = fopen("tests/output/obj/valid_str.json", "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
    free(str);
}

Test(json_parse_obj_from_str, test_json_parse_obj_from_str_invalid_eof)
{
    char* str = get_file_content("tests/file/obj/invalid_eof.json");
    json_object_t* obj;

    cr_assert(str != NULL);
    obj = json_parse_obj_from_str(str);
    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
    free(str);
}

Test(json_parse_obj_from_str, test_json_parse_obj_from_str_invalid_eof_excess)
{
    char* str = get_file_content("tests/file/obj/invalid_eof_excess.json");
    json_object_t* obj;

    cr_assert(str != NULL);
    obj = json_parse_obj_from_str(str);
    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
    free(str);
}
