#ifndef JSON_INTERNAL_TYPEDEF_ERROR_CODE_H_
#define JSON_INTERNAL_TYPEDEF_ERROR_CODE_H_

#define JSON_EXIT_SUCCESS 0
#define JSON_EXIT_FAILURE 1

typedef enum
{
    JSON_E_DEFAULT = 0,
    JSON_E_SYS_FAILURE,
    JSON_E_UNMATCHED_QUOTE, // Unmatched quote at parsing
    JSON_E_UNKNOW_TYPE,     // Unknow token type
    JSON_E_END_OF_FILE,     // End of file (Parser)
    JSON_E_SYNTHAX,
    JSON_E_KEY_DUPLICATED, // Key duplicated (Parser)
    JSON_E_INVALID_EOF,
    JSON_E_KEY_ALREADY_EXIST,

    JSON_E_COUNT // Count the number of error code
} json_errno_code_t;

#endif /* !JSON_INTERNAL_TYPEDEF_ERROR_CODE_H_ */
