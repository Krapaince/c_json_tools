#ifndef JSON_GENERATOR_H_
#define JSON_GENERATOR_H_

#include <json/type/array.h>
#include <json/type/object.h>
#include <json/internal/typedef/generator.h>

// generates a JSON object to the file descriptor (fd) from the obj.
// The file descriptor won't be closed after the generation of the object.
//
//   obj - must be a valid json_object_t pointer (not NULL)
//   fd  - a valid file directory
//   setting - sets the indent type and the size of the generator.
//     types:
//       TABULATION - the indentation character is set to '\t'
//       SPACE - the indentation character is set to ' '
//       NONE - the indentation is disables
//     The final indentation string use is composed of indent_size type.
//
//     If setting is null than the indent type will be set to SPACE and the
//     indent size to 4.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// in case of failure json_errno will be set
//
int json_object_generate_to_fd(json_object_t const* obj, int fd,
                               generator_setting_t const* setting);

// generates a JSON object to the file specify by filepath from the obj.
// The filepath is created if it doesn't exist or truncated if it exist.
//
//   obj - must be a valid json_object_t pointer (not NULL)
//   filepath - the path where the obj should be export
//   setting - sets the indent type and the size of the generator.
//     types:
//       TABULATION - the indentation character is set to '\t'
//       SPACE - the indentation character is set to ' '
//       NONE - the indentation is disables
//     The final indentation string use is composed of indent_size type.
//
//     If setting is null than the indent type will be set to SPACE and the
//     indent size to 4.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// in case of failure json_errno will be set
//
int json_object_generate_to_file(json_object_t const* obj, char const* filepath,
                                 generator_setting_t const* setting);

// generates a JSON object to *strptr from the obj.
//
//   obj - must be a valid json_object_t pointer (not NULL)
//   strptr - a pointer to the location of the output string.
//   setting - sets the indent type and the size of the generator.
//     types:
//       TABULATION - the indentation character is set to '\t'
//       SPACE - the indentation character is set to ' '
//       NONE - the indentation is disables
//     The final indentation string use is composed of indent_size type.
//
//     If setting is null than the indent type will be set to SPACE and the
//     indent size to 4.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// In case of failure json_errno will be set and *strptr will be left untouched.
//
int json_object_generate_to_string(json_object_t const* object,
                                   generator_setting_t const* setting,
                                   char** strptr);

// generates a JSON array to the file specify by filepath from the obj.
// The filepath is created if it doesn't exist or truncated if it exist.
//
//   array - must be a valid json_array_t pointer (not NULL)
//   filepath - the path where the obj should be export
//   setting - sets the indent type and the size of the generator.
//     types:
//       TABULATION - the indentation character is set to '\t'
//       SPACE - the indentation character is set to ' '
//       NONE - the indentation is disables
//     The final indentation string use is composed of indent_size type.
//
//     If setting is null than the indent type will be set to SPACE and the
//     indent size to 4.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// in case of failure json_errno will be set
//
int json_array_generate_to_fd(json_array_t const* array, int fd,
                              generator_setting_t const* setting);

// generates a JSON array to the file specify by filepath from the obj.
// The filepath is created if it doesn't exist or truncated if it exist.
//
//   array - must be a valid json_array_t pointer (not NULL)
//   filepath - the path where the obj should be export
//   setting - sets the indent type and the size of the generator.
//     types:
//       TABULATION - the indentation character is set to '\t'
//       SPACE - the indentation character is set to ' '
//       NONE - the indentation is disables
//     The final indentation string use is composed of indent_size type.
//
//     If setting is null than the indent type will be set to SPACE and the
//     indent size to 4.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// in case of failure json_errno will be set
//
int json_array_generate_to_file(json_array_t const* array, char const* filepath,
                                generator_setting_t const* setting);

// Generates a JSON array to *strptr from the obj.
//
//   array - must be a valid json_array_t pointer (not NULL)
//   strptr - a pointer to the location of the output string.
//   setting - sets the indent type and the size of the generator.
//     types:
//       TABULATION - the indentation character is set to '\t'
//       SPACE - the indentation character is set to ' '
//       NONE - the indentation is disables
//     The final indentation string use is composed of indent_size type.
//
//     If setting is null than the indent type will be set to SPACE and the
//     indent size to 4.
//
// Return:
//   Failure: JSON_EXIT_FAILURE
//   Success: JSON_EXIT_SUCCESS
//
// In case of failure json_errno will be set and *strptr will be left untouched.
//
int json_array_generate_to_string(json_array_t const* array,
                                  generator_setting_t const* setting,
                                  char** strptr);

#endif /* !JSON_GENERATOR_H_ */
