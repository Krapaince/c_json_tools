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

Test(json_parse_obj_from_fd, test_json_parse_obj_from_filepath_valid)
{
    int fd = open("tests/file/obj/valid.json", O_RDONLY);
    json_object_t* obj = json_parse_obj_from_fd(fd);
    FILE* expected = fopen("tests/expected/obj/valid.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(obj != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_generate_obj_to_file(obj, "tests/output/obj/valid_fd.json",
                                        &setting) == JSON_EXIT_SUCCESS);
    output = fopen("tests/output/obj/valid_fd.json", "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_object_destroy(obj);
    fclose(output);
    fclose(expected);
    close(fd);
}

Test(json_parse_obj_from_fd, test_json_parse_obj_from_fd_invalid_eof)
{
    int fd = open("tests/file/obj/invalid_eof.json", O_RDONLY);
    json_object_t* obj = json_parse_obj_from_fd(fd);

    cr_assert(obj == NULL);
    cr_assert(json_errno == JSON_E_INVALID_EOF);
    close(fd);
}
