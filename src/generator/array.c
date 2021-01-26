#include <json/internal/error.h>
#include <json/internal/generator/generate.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/generator.h>

static void json_generate_array_setup_context(generator_t* generator,
                                              json_array_t const* array)
{
    ++generator->depth;
    json_generate_type(generator, T_L_SQ_BRACKET);
    if (array->len)
    {
        json_generate_new_line(generator);
    }
}

static void json_generate_array_element(generator_t* generator,
                                        json_array_element_t const* element)
{
    json_generate_indent(generator);
    json_generate_union_value(generator, &element->value, element->type);
}

static void json_generate_array_teardown_context(generator_t* generator,
                                                 json_array_t const* array)
{
    --generator->depth;
    if (array->len)
    {
        json_generate_indent(generator);
    }
    json_generate_type(generator, T_R_SQ_BRACKET);
}

int json_generate_array(generator_t* generator, json_array_t const* array)
{
    size_t i = 0;
    int ret = JSON_EXIT_SUCCESS;

    json_generate_array_setup_context(generator, array);
    while (i < array->len)
    {
        json_generate_array_element(generator, &array->elements[i]);
        ++i;
        if (i < array->len)
        {
            json_generate_type(generator, T_COMMA);
        }
        json_generate_new_line(generator);
    }
    json_generate_array_teardown_context(generator, array);
    if (json_errno != JSON_E_DEFAULT)
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}
