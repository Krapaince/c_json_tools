#ifndef JSON_INTERNAL_TYPEDEF_ERROR_CODE_H_
#define JSON_INTERNAL_TYPEDEF_ERROR_CODE_H_

/// Json exit success value
#define JSON_ES 0
/// Json exit failure value
#define JSON_EF 1

/**
 * @defgroup ErrorErrnoValues
 * @{
 */

typedef enum
{
    /**
     * Default value
     */
    JSON_E_DEFAULT = 0,

    /**
     * Set when a call to a system function has failed (e.g.: malloc).
     */
    JSON_E_SYS_FAILURE,

    /**
     * \b Parser: Set when an unmatched quote was found during the parsing.
     */
    JSON_E_UNMATCHED_QUOTE,

    /**
     * \b Parser: Set when an unknow token was encountered during the parsing.
     */
    JSON_E_UNKNOW_TYPE,

    /**
     * \b Internal \b purpose \b only
     *
     * \b Parser: Set when the parser has reached the end of the file
     * descriptor but the parsed json is imcomplete.
     */
    JSON_E_END_OF_FILE,

    /**
     * \b Parser: Set when the token find by the parser isn't an expected token
     * type.
     */
    JSON_E_SYNTHAX,

    /**
     * \b Parser: Set when the parser found a duplicated key in an object.
     */
    JSON_E_KEY_DUPLICATED,

    /**
     * \b Parser: Set when the parser reached the end of the file/str but hasn't
     * reached the closing bracket.
     */
    JSON_E_INVALID_EOF,

    /**
     * Set when when the append value in an object has a key which already exist
     * in that object.
     */
    JSON_E_KEY_ALREADY_EXIST,

    /**
     * \b Internal \b purpose \b only
     *
     * ``json_errno`` is never set to this value.
     */
    JSON_E_COUNT
} json_errno_code_t;

/** @} */

#endif /* !JSON_INTERNAL_TYPEDEF_ERROR_CODE_H_ */
