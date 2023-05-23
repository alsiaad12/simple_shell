#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork() failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execlp(command, command, NULL);
        // If execlp returns, an error occurred
        perror("execlp() failed");
        exit(1);
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(void) {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        // Display prompt and wait for user input
        printf("$ ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            // Handle end of file condition (Ctrl+D)
            printf("\n");
            break;
        }

        // Remove newline character from command
        if (command[strlen(command) - 1] == '\n')
            command[strlen(command) - 1] = '\0';

        // Execute the command
        execute_command(command);
    }

    return 0;
}

