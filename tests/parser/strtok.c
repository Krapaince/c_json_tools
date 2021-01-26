#include <criterion/criterion.h>
#include <string.h>

#include <json/internal/error.h>
#include <json/internal/strtok.h>
#include <json/internal/typedef/parser.h>

Test(my_strtok, test_strtok_with_quote)
{
    char const* str = "\"\\\"titi\"titi";
    char* token = NULL;
    char* delimiter = " \t";
    char quote = '"';
    size_t i = 0;

    cr_assert(json_strtok(str, &i, delimiter, quote, &token) == JSON_ES);
    cr_expect_str_eq(token, "\"\"titi\"");
    cr_expect(i == 8);
    free(token);
}

Test(my_strtok, test_strtok_with_unmatched_quote)
{
    char const* str = "\"\\\"titititi";
    char* token = NULL;
    char* delimiter = " \t";
    char quote = '"';
    size_t i = 0;

    cr_assert(json_strtok(str, &i, delimiter, quote, &token) == JSON_EF);
    cr_expect(token == NULL);
    cr_expect(i == 0);
    cr_expect(json_errno == JSON_E_UNMATCHED_QUOTE);
}

Test(my_strtok, test_strtok_without_quote)
{
    char const* str = "   titi  ";
    char* token = NULL;
    char* delimiter = " \t";
    char quote = '"';
    size_t i = 0;

    cr_assert(json_strtok(str, &i, delimiter, quote, &token) == JSON_ES);
    cr_expect_str_eq(token, "titi");
    cr_expect(i == 7);
    free(token);
}

Test(my_strtok, test_strtok_with_empty_token)
{
    char const* str = "";
    char* token = NULL;
    char* delimiter = " \t";
    char quote = '"';
    size_t i = 0;

    cr_assert(json_strtok(str, &i, delimiter, quote, &token) == JSON_ES);
    cr_expect_str_eq(token, "");
    cr_expect(i == 0);
    free(token);
}

Test(my_strtok, test_strtok_with_quote_as_end_of_token)
{
    char const* str = "to\\\"ken\"";
    char* token = NULL;
    char* delimiter = " \t";
    char quote = '"';
    size_t i = 0;

    cr_assert(json_strtok(str, &i, delimiter, quote, &token) == JSON_ES);
    cr_expect_str_eq(token, "to\"ken");
    cr_expect(i == 7);
    free(token);
}
