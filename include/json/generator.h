#ifndef JSON_GENERATOR_H_
#define JSON_GENERATOR_H_

#include <json/internal/typedef/generator.h>
#include <json/type/array.h>
#include <json/type/object.h>

/**
 * @defgroup GeneratorObject
 * @{
 */

/**
 * The function generates ``obj`` to ``fd``. ``fd`` won't be closed after the
 * generation of the object.
 *
 * In case of failure ``json_errno`` will be set.
 *
 * @param obj       Is a pointer to valid ``json_object_t``
 * @param fd        A valid file descriptor
 * @param setting   Setting for the formatting
 *
 * @note If ``setting`` is null than the indent type will be set to ``SPACE``
 * and the indent size to 4.
 *
 * @retval JSON_EF On failure
 * @retval JSON_ES On success
 */
int json_object_generate_to_fd(json_object_t const* obj, int fd,
                               generator_setting_t const* setting);

/**
 * The function generates ``obj`` to the file specify by ``filepath``.
 *
 * The file at ``filepath`` is created if it doesn't exist or truncated if it
 * exist.
 *
 * In case of failure ``json_errno`` will be set.
 *
 * @param obj       Is a pointer to valid ``json_object_t``
 * @param filepath  The file in which the object will be exported
 * @param setting   Setting for the formatting
 *
 *  @note If ``setting`` is null than the indent type will be set to ``SPACE``
 * and the indent size to 4.
 *
 * @retval JSON_EF On failure
 * @retval JSON_ES On success
 *
 */
int json_object_generate_to_file(json_object_t const* obj, char const* filepath,
                                 generator_setting_t const* setting);

/*
 * The function generates ``obj`` to ``*strptr``.
 *
 * In case of failure ``json_errno`` will be set and *strptr will be left
 * untouched.
 *
 * @param obj       Is a pointer to valid ``json_object_t``
 * @param strptr    A pointer of string which will be allocated to contain the
 * exported object
 * @param setting   Setting for the formatting
 *
 * @note If setting is null than the indent type will be set to SPACE and the
 * indent size to 4.
 *
 * @retval JSON_EF On failure
 * @retval JSON_ES On success
 */
int json_object_generate_to_string(json_object_t const* object,
                                   generator_setting_t const* setting,
                                   char** strptr);

/** @} */

/**
 * @defgroup GeneratorArray
 * @{
 */

/**
 * The function generates ``array`` to ``fd``. ``fd`` won't be
 * closed after the generation of the array.
 *
 * In case of failure ``json_errno`` will be set.
 *
 * @param array     Is a pointer to valid ``json_array_t``
 * @param fd        A valid file descriptor
 * @param setting   Setting for the formatting
 *
 * @note If ``setting`` is null than the indent type will be set to ``SPACE``
 * and the indent size to 4.
 *
 * @retval JSON_EF On failure
 * @retval JSON_ES On success
 */
int json_array_generate_to_fd(json_array_t const* array, int fd,
                              generator_setting_t const* setting);

/**
 * The function generates ``array`` to the file specify by ``filepath``.
 *
 * The file at ``filepath`` is created if it doesn't exist or truncated if it
 * exist.
 *
 * In case of failure ``json_errno`` will be set.
 *
 * @param array     Is a pointer to valid ``json_array_t``
 * @param filepath  The file in which the object will be exported
 * @param setting   Setting for the formatting
 *
 *  @note If ``setting`` is null than the indent type will be set to ``SPACE``
 * and the indent size to 4.
 *
 * @retval JSON_EF On failure
 * @retval JSON_ES On success
 *
 */
int json_array_generate_to_file(json_array_t const* array, char const* filepath,
                                generator_setting_t const* setting);

/*
 * The function generates ``array`` to ``*strptr``.
 *
 * In case of failure ``json_errno`` will be set and *strptr will be left
 * untouched.
 *
 * @param array     Is a pointer to valid ``json_array_t``
 * @param strptr    A pointer of string which will be allocated to contain the
 * exported array
 * @param setting   Setting for the formatting
 *
 * @note If setting is null than the indent type will be set to SPACE and the
 * indent size to 4.
 *
 * @retval JSON_EF On failure
 * @retval JSON_ES On success
 */
int json_array_generate_to_string(json_array_t const* array,
                                  generator_setting_t const* setting,
                                  char** strptr);

/** @} */

#endif /* !JSON_GENERATOR_H_ */
