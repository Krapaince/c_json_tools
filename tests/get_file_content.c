#include <criterion/criterion.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int append_content_to_string(char** str, size_t* str_size,
                                    ssize_t nbytes, char const* content)
{
    char* tmp;
    int ret;
    size_t previous_size = *str_size;

    *str_size += nbytes;
    tmp = realloc(*str, (*str_size + 1) * sizeof(char));
    if (tmp)
    {
        strcpy(&tmp[previous_size], content);
        *str = tmp;
        ret = EXIT_SUCCESS;
    }
    else
    {
        ret = EXIT_FAILURE;
    }
    return ret;
}

static int get_file_content_getline(FILE* stream, char** str, size_t* str_size)
{
    char* buffer = NULL;
    size_t n = 0;
    ssize_t nbytes = getline(&buffer, &n, stream);

    while (nbytes != -1)
    {
        if (append_content_to_string(str, str_size, nbytes, buffer) ==
            EXIT_FAILURE)
        {
            free(buffer);
            return EXIT_FAILURE;
        }
        nbytes = getline(&buffer, &n, stream);
    }
    free(buffer);
    return EXIT_SUCCESS;
}

char* get_file_content(char const* filepath)
{
    FILE* stream = fopen(filepath, "r");
    char* str = NULL;
    size_t str_size = 0;
    int ret;

    if (stream)
    {
        ret = get_file_content_getline(stream, &str, &str_size);
        if (ret == EXIT_FAILURE)
        {
            free(str);
            str = NULL;
        }
        fclose(stream);
    }
    return str;
}

Test(get_file_content, test_get_file_centent_valid_filepath)
{
    char* str = get_file_content("tests/file/get_file_content.txt");
    char const* expected = "This\nis\na\nfile\nwith\ncontent.\n";

    cr_assert(str != NULL);
    cr_expect_str_eq(str, expected);
    free(str);
}

Test(get_file_content, test_get_file_centent_invalid_filepath)
{
    char* str = get_file_content("tests/invalid");

    cr_assert(str == NULL);
}
