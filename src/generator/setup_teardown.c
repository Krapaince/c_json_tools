/*
** EPITECH PROJECT, 2020
** json library
** File description:
** setup and teardown
*/

#include <string.h>

#include <error.h>
#include <typedef/generator.h>

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

int json_generator_setup(generator_t* generator,
                         generator_setting_t const* user_setting, int fd)
{
    size_t const buffer_size = 4096;
    write_buffer_t* buffer = &generator->buffer;
    int ret = JSON_EXIT_SUCCESS;

    buffer->value = malloc(sizeof(char) * buffer_size);
    if (buffer->value == NULL)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_SUCCESS;
    }
    else
    {
        generator->fd = fd;
        generator->depth = 0;
        buffer->len = 0;
        buffer->len_alloc = buffer_size;
        ret = json_setup_indent(generator, user_setting);
        if (ret != JSON_EXIT_SUCCESS)
        {
            free(buffer->value);
        }
    }
    return ret;
}

void json_generator_teardown(generator_t* generator)
{
    free(generator->indent);
    free(generator->buffer.value);
}
