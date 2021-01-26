#ifndef JSON_INTERNAL_ERROR_H_
#define JSON_INTERNAL_ERROR_H_

#include <stddef.h>

#include <json/internal/typedef/error.h>
#include <json/internal/typedef/error_code.h>

extern unsigned char* json_errno_location(void);
#define json_errno (*json_errno_location())

void json_errno_reset(void);

extern size_t* json_error_line_location(void);
#define json_error_line (*json_error_line_location())

#endif /* !JSON_INTERNAL_ERROR_H_ */
