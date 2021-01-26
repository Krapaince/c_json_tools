#include <json/internal/error.h>
#include <json/internal/generator/generate.h>
#include <json/internal/typedef/generator.h>
#include <json/internal/typedef/object.h>

static void json_generate_object_setup_context(generator_t* generator,
                                               json_object_t const* obj)
{
    ++generator->depth;
    json_generate_type(generator, T_L_BRACKET);
    if (obj->len)
    {
        json_generate_new_line(generator);
    }
}

static void json_generate_object_element(generator_t* generator,
                                         json_object_element_t const* element)
{
    json_generate_indent(generator);
    json_generate_str(generator, &element->key);
    json_generate_type(generator, T_COLON);
    json_generate_space(generator);
    json_generate_union_value(generator, &element->value, element->type);
}

static void json_generate_object_teardown_context(generator_t* generator,
                                                  json_object_t const* obj)
{
    --generator->depth;
    if (obj->len)
    {
        json_generate_indent(generator);
    }
    json_generate_type(generator, T_R_BRACKET);
}

int json_generate_object(generator_t* generator, json_object_t const* obj)
{
    size_t i = 0;
    int ret = JSON_EXIT_SUCCESS;

    json_generate_object_setup_context(generator, obj);
    while (i < obj->len)
    {
        json_generate_object_element(generator, &obj->elements[i]);
        ++i;
        if (i < obj->len)
        {
            json_generate_type(generator, T_COMMA);
        }
        json_generate_new_line(generator);
    }
    json_generate_object_teardown_context(generator, obj);
    if (json_errno != JSON_E_DEFAULT)
    {
        ret = JSON_EXIT_FAILURE;
    }
    return ret;
}
