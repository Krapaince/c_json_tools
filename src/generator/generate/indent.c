/*
** EPITECH PROJECT, 2020
** json library
** File description:
** indent.c
*/

#include <error.h>
#include <generator/generate.h>
#include <typedef/generator.h>

int json_generate_indent(generator_t* generator)
{
    size_t i = 0;
    int ret = JSON_EXIT_SUCCESS;

    if (generator->type != DISABLE)
    {
        while (i < generator->depth && ret == JSON_EXIT_SUCCESS)
        {
            ret = json_generate_to_buffer(generator, generator->indent,
                                          generator->len_indent);
            ++i;
        }
    }
    return ret;
}

int json_generate_space(generator_t* generator)
{
    int ret = JSON_EXIT_SUCCESS;

    if (generator->type != DISABLE)
    {
        ret = json_generate_to_buffer(generator, " ", 1);
    }
    return ret;
}

int json_generate_new_line(generator_t* generator)
{
    int ret = JSON_EXIT_SUCCESS;

    if (generator->type != DISABLE)
    {
        ret = json_generate_to_buffer(generator, "\n", 1);
    }
    return ret;
}
