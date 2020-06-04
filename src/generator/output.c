/*
** EPITECH PROJECT, 2020
** json library
** File description:
** generator output
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
    int ret;
    generator_buffer_t* buffer = &generator->buffer;
    char* temp =
        realloc(buffer->value,
                sizeof(char) * (buffer->len_alloc + GENERATOR_BUFFER_SIZE + 1));

    if (temp == NULL)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        buffer->value = temp;
        buffer->len_alloc += GENERATOR_BUFFER_SIZE;
        ret = JSON_EXIT_SUCCESS;
    }
    return ret;
}

int json_generate_to_output(generator_t* generator)
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
