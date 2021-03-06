#include <json/internal/error.h>
#include <json/internal/generator.h>
#include <json/internal/generator/generate.h>
#include <json/internal/typedef/generator.h>
#include <json/internal/typedef/type.h>

int json_generate_union_value(generator_t* generator,
                              json_union_value_t const* value, json_type_t type)
{
    switch (type)
    {
        case JSON_BOOL:
            if (value->boolean == true)
            {
                return json_generate_type(generator, T_BOOL_TRUE);
            }
            else
            {
                return json_generate_type(generator, T_BOOL_FALSE);
            }
        case JSON_NB:
            return json_generate_nb(generator, value->nb);
        case JSON_STR:
            return json_generate_str(generator, &value->str);
        case JSON_NULL:
            return json_generate_type(generator, T_NULL);
        case JSON_ARRAY:
            return json_generate_array(generator, value->array);
        case JSON_OBJ:
            return json_generate_object(generator, value->obj);
    }
    return JSON_ES;
}
