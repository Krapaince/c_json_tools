#include <json/internal/editor/compare.h>
#include <json/internal/editor/destroy/union.h>
#include <json/internal/typedef/array.h>

// Since the element that is used to compare may be an element inside our array
// we need to keep it until the end of the array. In order to do that, the
// element is store in *ref_element.
static void json_array_destroy_element(json_array_element_t* element,
                                       json_array_element_t const* ref,
                                       json_array_element_t** ref_element)
{
    json_type_t type = element->type;
    size_t i = 0;
    json_type_t const types[] = {JSON_STR, JSON_OBJ, JSON_ARRAY};
    void* const ptr_element[] = {element->value.str.value, element->value.obj,
                                 element->value.array, NULL};
    void* const ptr_ref[] = {ref->value.str.value, ref->value.obj,
                             ref->value.array, NULL};

    while (ptr_element[i])
    {
        if (element->type == types[i] && ptr_element[i] == ptr_ref[i])
        {
            *ref_element = element;
            return;
        }
        ++i;
    }
    json_union_value_destroy(&element->value, type);
}

static size_t json_array_unset_elements_by_value_core(
    json_array_t* array, json_array_element_t const* element,
    json_array_element_t** ref_element)
{
    size_t i = 0;
    size_t arr_cur_i = 0;
    size_t nb_elem_unset;
    json_array_element_t* current;

    while (i < array->len)
    {
        current = &array->elements[i];
        if (json_compare_element(&current->value, current->type,
                                 &element->value, element->type))
        {
            json_array_destroy_element(current, element, ref_element);
        }
        else
        {
            array->elements[arr_cur_i] = *current;
            ++arr_cur_i;
        }
        ++i;
    }
    nb_elem_unset = array->len - arr_cur_i;
    array->len = arr_cur_i;
    return nb_elem_unset;
}

size_t json_array_unset_elements_by_value(json_array_t* array,
                                          json_array_element_t const* element)
{
    json_array_element_t* ref_element = NULL;
    size_t ret =
        json_array_unset_elements_by_value_core(array, element, &ref_element);

    if (ref_element)
    {
        json_union_value_destroy(&ref_element->value, ref_element->type);
    }
    return ret;
}
