/*
** EPITECH PROJECT, 2020
** json library
** File description:
** write union
*/

#include <error.h>
#include <generator.h>
#include <generator/write.h>
#include <typedef/generator.h>
#include <typedef/type.h>

int json_write_union_value(generator_t* generator,
                           json_union_value_t const* value, json_type_t type)
{
    switch (type)
    {
        case JSON_BOOL:
            if (value->boolean == true)
            {
                return json_write_type(generator, T_BOOL_TRUE);
            }
            else
            {
                return json_write_type(generator, T_BOOL_FALSE);
            }
        case JSON_NB:
            return json_write_nb(generator, value->nb);
        case JSON_STR:
            return json_write_str(generator, &value->str);
        case JSON_NULL:
            return json_write_type(generator, T_NULL);
        case JSON_ARRAY:
            return json_generate_array(generator, value->array);
        case JSON_OBJ:
            return json_generate_object(generator, value->obj);
    }
    return JSON_EXIT_SUCCESS;
}
