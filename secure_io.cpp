#include <stdio.h>
#include <ctype.h>
#include "secure_io.h"

char *secure_gets(char *buffer, size_t buffer_size) {
    // Check that the buffer is not NULL and has non-zero size
    if (buffer == NULL || buffer_size == 0) {
        return NULL;
    }

    // Use fgets to read a line of input from stdin
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        return NULL;
    }

    // Remove the newline character at the end of the input if present
    size_t length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    }

    // Return a pointer to the resulting string
    return buffer;
}

int secure_scanf_int(void) {
    int value;
    char buffer[100];

    while (1) {
        // Use secure_gets to read a line of input
        if (secure_gets(buffer, sizeof(buffer)) == NULL) {
            // An error occurred, return 0
            return 0;
        }

        // Try to convert the input to an integer using sscanf
        if (sscanf(buffer, "%d", &value) == 1) {
            // The input was a valid integer, return it
            return value;
        }

        // The input was not a valid integer, display an error message and try again
        printf("Invalid input, please enter an integer: ");
    }
}

double secure_scanf_double(void) {
    double value;
    char buffer[100];

    while (1) {
        // Use secure_gets to read a line of input
        if (secure_gets(buffer, sizeof(buffer)) == NULL) {
            // An error occurred, return 0.0
            return 0.0;
        }

        // Try to convert the input to a double using sscanf
        if (sscanf(buffer, "%lf", &value) == 1) {
            // The input was a valid double, return it
            return value;
        }

        // The input was not a valid double, display an error message and try again
        printf("Invalid input, please enter a double: ");
    }
}


