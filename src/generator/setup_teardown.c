#include <string.h>

#include <json/internal/error.h>
#include <json/internal/typedef/generator.h>

static int json_setup_indent(generator_t* generator,
                             generator_setting_t const* user_setting)
{
    int ret = JSON_EXIT_SUCCESS;
    generator_setting_t setting = {SPACE, 4};

    if (user_setting)
    {
        setting = *user_setting;
    }
    if (setting.type != DISABLE)
    {
        generator->type = setting.type;
        generator->len_indent = setting.indent_size;
        generator->indent = calloc(setting.indent_size + 1, sizeof(char));
        if (generator->indent)
        {
            memset(generator->indent, generator->type, generator->len_indent);
        }
        else
        {
            json_errno = JSON_E_SYS_FAILURE;
            ret = JSON_EXIT_FAILURE;
        }
    }
    return ret;
}

static int json_generator_setup(generator_t* generator,
                                generator_setting_t const* user_setting)
{
    generator_buffer_t* buffer = &generator->buffer;
    int ret = JSON_EXIT_SUCCESS;

    memset(generator, 0, sizeof(generator_t));
    buffer->value = calloc((GENERATOR_BUFFER_SIZE + 1), sizeof(char));
    if (buffer->value == NULL)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        generator->depth = 0;
        buffer->len = 0;
        buffer->len_alloc = GENERATOR_BUFFER_SIZE;
        ret = json_setup_indent(generator, user_setting);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(buffer->value);
        }
    }
    return ret;
}

int json_generator_setup_file(generator_t* generator,
                              generator_setting_t const* user_setting, int fd)
{
    int ret = json_generator_setup(generator, user_setting);

    if (ret == JSON_EXIT_SUCCESS)
    {
        generator->output.type = GENERATOR_OUTPUT_FILE;
        generator->output.fd = fd;
    }
    return ret;
}

int json_generator_setup_string(generator_t* generator,
                                generator_setting_t const* user_setting)
{
    int ret = json_generator_setup(generator, user_setting);

    if (ret == JSON_EXIT_SUCCESS)
    {
        generator->output.type = GENERATOR_OUTPUT_STRING;
    }
    return ret;
}

void json_generator_teardown(generator_t* generator)
{
    free(generator->indent);
    free(generator->buffer.value);
}
