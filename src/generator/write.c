/*
** EPITECH PROJECT, 2020
** json library
** File description:
** write wrapper
*/

#include <string.h>
#include <unistd.h>

#include <error.h>
#include <typedef/generator.h>
#include <typedef/token.h>

static int json_generate_write_to_output(generator_t* generator)
{
    generator_buffer_t* buffer = &generator->buffer;
    ssize_t nbytes = write(generator->output.fd, buffer->value, buffer->len);
    int ret;

    if (nbytes != (ssize_t)buffer->len)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        generator->buffer.len = 0;
        ret = JSON_EXIT_SUCCESS;
    }
    return ret;
}

static int json_generate_append_to_output(generator_t* generator)
{
    generator_buffer_t* buffer = &generator->buffer;
    generator_output_t* output = &generator->output;
    char* temp = NULL;
    size_t left_space = output->len_alloc - output->len;

    if (left_space < buffer->len)
    {
        temp = realloc(output->str, sizeof(char) * (output->len_alloc +
                                                    GENERATOR_BUFFER_SIZE + 1));
        if (temp == NULL)
        {
            json_errno = JSON_E_SYS_FAILURE;
            return JSON_EXIT_FAILURE;
        }
        output->str = temp;
        output->len_alloc += GENERATOR_BUFFER_SIZE;
    }
    memcpy(&output->str[output->len], buffer->value, buffer->len);
    output->len += buffer->len;
    output->str[output->len] = '\0';
    buffer->len = 0;
    return JSON_EXIT_SUCCESS;
}

int json_write(generator_t* generator)
{
    int ret;

    if (generator->output.type == GENERATOR_OUTPUT_FILE)
    {
        ret = json_generate_write_to_output(generator);
    }
    else
    {
        ret = json_generate_append_to_output(generator);
    }
    return ret;
}

int json_write_buffer(generator_t* generator, char const* str, size_t len)
{
    int ret = JSON_EXIT_SUCCESS;
    generator_buffer_t* buffer = &generator->buffer;
    size_t remaining_space;
    size_t pos = 0;

    while (len && ret == JSON_EXIT_SUCCESS)
    {
        remaining_space = buffer->len_alloc - buffer->len;
        if (len <= remaining_space)
        {
            strncpy(&buffer->value[buffer->len], &str[pos], len);
            buffer->len += len;
            len = 0;
        }
        else
        {
            strncpy(&buffer->value[buffer->len], &str[pos], remaining_space);
            len -= remaining_space;
            pos += remaining_space;
            buffer->len += remaining_space;
            ret = json_write(generator);
            buffer->len = 0;
        }
    }
    return ret;
}
