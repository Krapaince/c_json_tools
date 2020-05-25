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
#include <typedef/array.h>
#include <typedef/generator.h>

int json_array_generate_to_fd(json_array_t const* array, int fd,
                              generator_setting_t const* setting)
{
    generator_t generator;
    int ret;

    memset(&generator, 0, sizeof(generator_t));
    json_errno = JSON_E_DEFAULT;
    ret = json_generator_setup(&generator, setting, fd);
    json_errno_reset();
    if (ret == JSON_EXIT_SUCCESS)
    {
        ret = json_generate_array(&generator, array);
        if (ret == JSON_EXIT_SUCCESS)
        {
            ret = json_write(&generator);
        }
        json_generator_teardown(&generator);
    }
    return ret;
}

int json_array_generate_to_file(json_array_t const* array, char const* filepath,
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
        ret = json_array_generate_to_fd(array, fd, setting);
        close(fd);
    }
    return ret;
}
