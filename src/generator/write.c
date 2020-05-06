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

int json_write(generator_t* generator)
{
    write_buffer_t* buffer = &generator->buffer;
    ssize_t nbytes = write(generator->fd, buffer->value, buffer->len);
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

int json_write_buffer(generator_t* generator, char const* str, size_t len)
{
    int ret = JSON_EXIT_SUCCESS;
    write_buffer_t* buffer = &generator->buffer;
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
