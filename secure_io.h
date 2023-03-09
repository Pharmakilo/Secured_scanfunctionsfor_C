#ifndef SECURE_IO_H
#define SECURE_IO_H

#include <stdlib.h>
#include <string.h>

// Reads a line of input from stdin into the specified buffer, up to buffer_size - 1 characters.
// Truncates the input if it is longer than buffer_size - 1 characters.
// Removes the newline character at the end of the input if present.
// Returns a pointer to the resulting string, or NULL if an error occurred.
char *secure_gets(char *buffer, size_t buffer_size);

// Reads an integer from stdin, validating the input.
// If the input is not a valid integer, displays an error message and asks the user to try again.
// Returns the valid integer.
int secure_scanf_int(void);

// Reads a double from stdin, validating the input.
// If the input is not a valid double, displays an error message and asks the user to try again.
// Returns the valid double.
double secure_scanf_double(void);

#endif  // SECURE_IO_H

