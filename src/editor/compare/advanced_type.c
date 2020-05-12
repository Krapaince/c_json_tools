/*
** EPITECH PROJECT, 2020
** json library
** File description:
** editor compare object
*/

#include <editor/compare.h>
#include <json/editor/compare.h>
#include <typedef/object.h>

bool json_compare_element(json_union_value_t const* value1, json_type_t type1,
                          json_union_value_t const* value2, json_type_t type2)
{
    bool ret = type1 == type2;

    if (ret)
    {
        switch (type1)
        {
            case JSON_BOOL:
                return json_compare_bool(value1->boolean, value2->boolean);
            case JSON_NB:
                return json_compare_nb(value1->nb, value2->nb);
            case JSON_STR:
                return json_compare_str(&value1->str, &value2->str);
            case JSON_NULL:
                return json_compare_null(value1->null, value2->null);
            case JSON_OBJ:
                return json_object_compare(value1->obj, value2->obj);
            case JSON_ARRAY:
                return json_array_compare(value1->array, value2->array);
        }
    }
    return ret;
}

bool json_object_compare(json_object_t const* obj1, json_object_t const* obj2)
{
    size_t i = 0;
    bool ret = obj1->len == obj2->len;

    while (i < obj1->len && ret)
    {
        ret = json_compare_element(
            &obj1->elements[i].value, obj1->elements[i].type,
            &obj2->elements[i].value, obj2->elements[i].type);
        ++i;
    }
    return ret;
}

bool json_array_compare(json_array_t const* array1, json_array_t const* array2)
{
    size_t i = 0;
    bool ret = array1->len == array2->len;

    while (i < array1->len && ret)
    {
        ret = json_compare_element(
            &array1->elements[i].value, array1->elements[i].type,
            &array2->elements[i].value, array2->elements[i].type);
        ++i;
    }
    return ret;
}
