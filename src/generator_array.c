#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include <json/internal/error.h>
#include <json/internal/generator.h>
#include <json/internal/generator/generate.h>
#include <json/internal/typedef/array.h>
#include <json/internal/typedef/generator.h>

int json_array_generate_to_fd(json_array_t const* array, int fd,
                              generator_setting_t const* setting)
{
    generator_t generator;
    int ret;

    json_errno = JSON_E_DEFAULT;
    ret = json_generator_setup_file(&generator, setting, fd);
    json_errno_reset();
    if (ret == JSON_ES)
    {
        ret = json_generate_array(&generator, array);
        if (ret == JSON_ES)
        {
            ret = json_generate_to_output(&generator);
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
        ret = JSON_EF;
    }
    else
    {
        ret = json_array_generate_to_fd(array, fd, setting);
        close(fd);
    }
    return ret;
}

int json_array_generate_to_string(json_array_t const* array,
                                  generator_setting_t const* setting,
                                  char** strptr)
{
    generator_t generator;
    int ret;

    json_errno_reset();
    ret = json_generator_setup_string(&generator, setting);
    if (ret != JSON_ES)
    {
        return ret;
    }
    ret = json_generate_array(&generator, array);
    if (ret == JSON_ES)
    {
        ret = json_generate_to_output(&generator);
        if (ret == JSON_ES)
        {
            *strptr = generator.buffer.value;
            generator.buffer.value = NULL;
        }
    }
    json_generator_teardown(&generator);
    return ret;
}
