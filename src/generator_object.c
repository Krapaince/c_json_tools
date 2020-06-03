/*
** EPITECH PROJECT, 2020
** jsin library
** File description:
** generator
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <error.h>
#include <generator.h>
#include <generator/write.h>
#include <typedef/generator.h>
#include <typedef/object.h>

int json_object_generate_to_fd(json_object_t const* obj, int fd,
                               generator_setting_t const* setting)
{
    generator_t generator;
    int ret;

    json_errno = JSON_E_DEFAULT;
    ret = json_generator_setup_file(&generator, setting, fd);
    json_errno_reset();
    if (ret == JSON_EXIT_SUCCESS)
    {
        ret = json_generate_object(&generator, obj);
        if (ret == JSON_EXIT_SUCCESS)
        {
            ret = json_generate_to_output(&generator);
        }
        json_generator_teardown(&generator);
    }
    return ret;
}

int json_object_generate_to_file(json_object_t const* obj, char const* filepath,
                                 generator_setting_t const* setting)
{
    int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    int ret;

    if (fd == -1)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EXIT_FAILURE;
    }
    else
    {
        ret = json_object_generate_to_fd(obj, fd, setting);
        close(fd);
    }
    return ret;
}

int json_object_generate_to_string(json_object_t const* object,
                                   generator_setting_t const* setting,
                                   char** strptr)
{
    generator_t generator;
    int ret;

    json_errno_reset();
    ret = json_generator_setup_string(&generator, setting);
    if (ret != JSON_EXIT_SUCCESS)
    {
        return ret;
    }
    ret = json_generate_object(&generator, object);
    if (ret == JSON_EXIT_SUCCESS)
    {
        ret = json_generate_to_output(&generator);
        if (ret == JSON_EXIT_SUCCESS)
        {
            *strptr = generator.output.str;
            generator.output.str = NULL;
        }
    }
    json_generator_teardown(&generator);
    return ret;
}
