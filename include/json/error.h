#ifndef JSON_ERROR_H_
#define JSON_ERROR_H_

#include <stddef.h>
#include <stdio.h>

#include <json/internal/typedef/error_code.h>

/**
 * @defgroup ErrorErrno
 * @{
 */

/**
 * \b Internal \b purpose \b only
 *
 * The internal errno function of this library.
 */
extern unsigned char* json_errno_location(void);

/**
 * Just a simple define to simplify the access to the errno's value.
 */
#define json_errno (*json_errno_location())

/**
 * This function writes an error accordong to the value or ``json_errno``.
 */
void json_print_error(FILE* stream);

/**
 * @}
 */

#endif /* !JSON_ERROR_H_ */
