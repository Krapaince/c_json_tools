#include <string.h>
#include <unistd.h>

#include <json/internal/error.h>
#include <json/internal/typedef/generator.h>
#include <json/internal/typedef/token.h>

static int json_generate_write_to_output(generator_t* generator)
{
    generator_buffer_t* buffer = &generator->buffer;
    ssize_t nbytes = write(generator->output.fd, buffer->value, buffer->len);
    int ret;

    if (nbytes != (ssize_t)buffer->len)
    {
        json_errno = JSON_E_SYS_FAILURE;
        ret = JSON_EF;
    }
    else
    {
        generator->buffer.len = 0;
        ret = JSON_ES;
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
        ret = JSON_EF;
    }
    else
    {
        memset(&temp[buffer->len_alloc], 0, GENERATOR_BUFFER_SIZE + 1);
        buffer->value = temp;
        buffer->len_alloc += GENERATOR_BUFFER_SIZE;
        ret = JSON_ES;
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
