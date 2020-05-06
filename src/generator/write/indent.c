/*
** EPITECH PROJECT, 2020
** json library
** File description:
** indent.c
*/

#include <error.h>
#include <generator/write.h>
#include <typedef/generator.h>

int json_write_indent(generator_t* generator)
{
    size_t i = 0;
    int ret = JSON_EXIT_SUCCESS;

    if (generator->type != DISABLE)
    {
        while (i < generator->depth && ret == JSON_EXIT_SUCCESS)
        {
            ret = json_write_buffer(generator, generator->indent,
                                    generator->len_indent);
            ++i;
        }
    }
    return ret;
}

int json_write_space(generator_t* generator)
{
    int ret = JSON_EXIT_SUCCESS;

    if (generator->type != DISABLE)
    {
        ret = json_write_buffer(generator, " ", 1);
    }
    return ret;
}

int json_write_new_line(generator_t* generator)
{
    int ret = JSON_EXIT_SUCCESS;

    if (generator->type != DISABLE)
    {
        ret = json_write_buffer(generator, "\n", 1);
    }
    return ret;
}
