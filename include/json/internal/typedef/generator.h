#ifndef JSON_INTERNAL_TYPEDEF_GENERATOR_H_
#define JSON_INTERNAL_TYPEDEF_GENERATOR_H_

#include <stdlib.h>

#define GENERATOR_BUFFER_SIZE 4096

typedef enum
{
    GENERATOR_OUTPUT_STRING,
    GENERATOR_OUTPUT_FILE
} generator_output_type_t;

typedef struct
{
    generator_output_type_t type;
    union
    {
        int fd;
    };
} generator_output_t;

/**
 * @defgroup GeneratorSetting
 * @{
 */

/**
 * An enum class to regroup each indentation types available.
 */
typedef enum
{
    /**
     * Sets ``\t`` as indentation character.
     */
    TABULATION = '\t',

    /**
     * Sets ``'  '`` as indentation character.
     */
    SPACE = ' ',

    /**
     * Disables the indentation.
     */
    DISABLE = '\0'
} indent_type_t;

/**
 * The ``generator_setting_t`` structure allow the user to generate a
 * ``json_*_t`` via the function ``json_generate_*`` with a custom formatting.
 */
typedef struct
{
    indent_type_t type;

    /**
     * The ``indent_size`` sets the number of ``indent_type_t`` generated in the
     * output. \b Be \b careful with ``TABULATION`` a value of `4` will generate
     * for ``TABULATION`` in the final output.
     */
    size_t indent_size;
} generator_setting_t;

/** @} */

typedef struct
{
    char* value;
    size_t len;
    size_t len_alloc;
} generator_buffer_t;

typedef struct
{
    generator_output_t output;

    indent_type_t type;
    char* indent;
    size_t len_indent;
    size_t depth;

    generator_buffer_t buffer;
} generator_t;

#endif /* !JSON_INTERNAL_TYPEDEF_GENERATOR_H_ */
