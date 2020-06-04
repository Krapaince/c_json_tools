/*
** EPITECH PROJECT, 2020
** json library
** File description:
** generator buffer
*/

#include <string.h>

#include <error.h>
#include <generator/generate.h>
#include <typedef/generator.h>

int json_generate_to_buffer(generator_t* generator, char const* str, size_t len)
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
            ret = json_generate_to_output(generator);
        }
    }
    return ret;
}
