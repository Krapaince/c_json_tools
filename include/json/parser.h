#ifndef JSON_PARSER_H_
#define JSON_PARSER_H_

#include <json/type/array.h>
#include <json/type/object.h>

/**
 * @defgroup ParserObject
 * @{
 */

/**
 * The function parses a JSON object out of ``fd``. When the end of the
 * object is reached, the function returns the parsed object and let ``fd``
 * open.
 *
 * In case of failure ``json_errno`` is set.
 *
 * @note ``json_errno`` is reset before the parsing of the object.
 *
 * @retval NULL On failure
 * @retval A pointer to an allocated ``json_object_t``.
 */
json_object_t* json_object_parse_from_fd(int fd);

/**
 * The functions parses a JSON object out of the file at ``filepath``. If
 * after the object there isn't only whitespace characters, the function fails.
 *
 * In case of failure ``json_errno`` is set.
 *
 * @note ``json_errno`` is reset before the parsing of the object.
 *
 * @retval NULL On failure
 * @retval A pointer to an allocated ``json_object_t``.
 *
 */
json_object_t* json_object_parse_from_filepath(char const* filepath);

/**
 * The function parses a JSON object out of ``str``. If the function succeed and
 * ``index`` is not null, ``*index`` will be set with the ``index`` at which the
 * parser stopped in ``str``.
 *
 * In case of failure ``json_errno`` is set.
 *
 * @note ``json_errno`` is reset before the parsing of the object.
 *
 * @retval NULL On failure
 * @retval A pointer to an allocated ``json_object_t``.
 *
 */
json_object_t* json_object_parse_from_str(char const* str, size_t* index);

/** @} */

/**
 * @defgroup ParserArray
 * @{
 */

/**
 * The functions parses a JSON array out of ``fd``. When the end of the
 * array is reached, the function returns the parsed arrat and let ``fd``
 * open.
 *
 * In case of failure ``json_errno`` is set.
 *
 * @note ``json_errno`` is reset before the parsing of the array.
 *
 * @retval NULL On failure
 * @retval A pointer to an allocated ``json_array_t``.
 *
 */
json_array_t* json_array_parse_from_fd(int fd);

/**
 * The functions parses a JSON array out of the file at ``filepath``. If
 * after the array there isn't only whitespace characters, the function fails.
 *
 * In case of failure ``json_errno`` is set.
 *
 * @note ``json_errno`` is reset before the parsing of the array.
 *
 * @retval NULL On failure
 * @retval A pointer to an allocated ``json_array_t``.
 *
 */
json_array_t* json_array_parse_from_filepath(char const* filepath);

/**
 * The function parses a JSON array out of ``str``. If the function succeed and
 * ``index`` is not null, ``*index`` will be set with the ``index`` at which the
 * parser stopped in ``str``.
 *
 * In case of failure ``json_errno`` is set.
 *
 * @note ``json_errno`` is reset before the parsing of the array.
 *
 * @retval NULL On failure
 * @retval A pointer to an allocated ``json_array_t``.
 *
 */
json_array_t* json_array_parse_from_str(char const* str, size_t* index);

/** @} */

#endif /* !JSON_PARSER_H_ */
