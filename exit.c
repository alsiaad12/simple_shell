#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit_shell() {
    exit(0);
}

int main(void) {
    char input[100];
    
    // Read user input
    printf("$ ");
    fgets(input, sizeof(input), stdin);
    
    // Remove newline character from input
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    // Check if the input is "exit"
    if (strcmp(input, "exit") == 0) {
        exit_shell();
    }
    
    return 0;
}

