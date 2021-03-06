#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include <json/editor/destroy.h>
#include <json/error.h>
#include <json/generator.h>
#include <json/parser.h>

Test(json_array_parse_from_fd, test_json_array_parse_from_filepath_valid)
{
    int fd = open("tests/file/array/valid.json", O_RDONLY);
    json_array_t* array = json_array_parse_from_fd(fd);
    FILE* expected = fopen("tests/expected/array/valid.json", "r");
    FILE* output;
    generator_setting_t setting = {SPACE, 2};

    cr_assert(array != NULL);
    cr_assert(json_errno == JSON_E_DEFAULT);
    cr_assert(json_array_generate_to_file(array,
                                          "tests/output/array/valid_fd.json",
                                          &setting) == JSON_ES);
    output = fopen("tests/output/array/valid_fd.json", "r");
    cr_assert(expected != NULL);
    cr_assert(output != NULL);
    cr_expect_file_contents_eq(output, expected);
    json_array_destroy(array);
    fclose(output);
    fclose(expected);
    close(fd);
}
