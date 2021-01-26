#ifndef JSON_INTERNAL_GENERATOR_H_
#define JSON_INTERNAL_GENERATOR_H_

#include <json/internal/typedef/generator.h>
#include <json/internal/typedef/object.h>

int json_generator_setup_string(generator_t* generator,
                                generator_setting_t const* user_setting);

int json_generator_setup_file(generator_t* generator,
                              generator_setting_t const* user_setting, int fd);

void json_generator_teardown(generator_t* generator);

int json_generate_object(generator_t* generator, json_object_t const* obj);
int json_generate_array(generator_t* generator, json_array_t const* array);

#endif /* !JSON_INTERNAL_GENERATOR_H_ */
