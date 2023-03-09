#include <stdio.h>
#include <ctype.h>
#include "secure_io.h"

char *secure_gets(char *buffer, size_t buffer_size) {
    
    if (buffer == NULL || buffer_size == 0) {
        return NULL;
    }
    if (fgets(buffer, buffer_size, stdin) == NULL) {
        return NULL;
    }

    
    size_t length = strlen(buffer);
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = '\0';
    }

    
    return buffer;
}

int secure_scanf_int(void) {
    int value;
    char buffer[100];

    while (1) {
        
        if (secure_gets(buffer, sizeof(buffer)) == NULL) {
           
            return 0;
        }

        
        if (sscanf(buffer, "%d", &value) == 1) {
           
            return value;
        }
        printf("Invalid input, please enter an integer: ");
    }
}

double secure_scanf_double(void) {
    double value;
    char buffer[100];

    while (1) {
        
        if (secure_gets(buffer, sizeof(buffer)) == NULL) {
           
            return 0.0;
        }

        
        if (sscanf(buffer, "%lf", &value) == 1) {
            
            return value;
        }
        printf("Invalid input, please enter a double: ");
    }
}


