/*
 * name: Gustavo Ferreira Gitzel
 * ra: 223559
 * class: MC504 A
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PATHS 100
#define MAX_CMD_LEN 1024

void replace_env_vars(char *args[]) {
    for (int i = 0; args[i] != NULL; i++) {
        if (args[i][0] == '$') {
            char *env_var = getenv(args[i] + 1);
            if (env_var) {
                args[i] = env_var;
            }
        }
    }
}

void execute_command(char *paths[], char *args[], char *output_file) {
    char cmd_path[MAX_CMD_LEN];
    int fd = -1;

    if (output_file) {
        fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("error opening output file");
            exit(EXIT_FAILURE);
        }
        dup2(fd, STDOUT_FILENO);
    }

    // if the command is an absolute path
    if (args[0][0] == '/') {
        execv(args[0], args);
        fprintf(stderr, "error: command '%s' not found.\n", args[0]);

        if (fd != -1) {
            close(fd);
        }
        exit(EXIT_FAILURE);
    }

    // otherwise search in the specified directories
    for (int i = 0; paths[i] != NULL; i++) {
        snprintf(cmd_path, sizeof(cmd_path), "%s/%s", paths[i], args[0]);
        execv(cmd_path, args);
    }

    fprintf(stderr, "error: command '%s' was not found in the specified directories.\n", args[0]);

    if (fd != -1) {
        close(fd);
    }
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <directories>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *paths[MAX_PATHS];
    char *token = strtok(argv[1], ":");
    int path_count = 0;

    while (token != NULL && path_count < MAX_PATHS) {
        paths[path_count++] = token;
        token = strtok(NULL, ":");
    }
    paths[path_count] = NULL;

    char command[MAX_CMD_LEN];
    printf("simple-shell$: ");
    if (fgets(command, sizeof(command), stdin) == NULL) {
        perror("Error reading command");
        return EXIT_FAILURE;
    }

    command[strcspn(command, "\n")] = '\0';

    char *args[MAX_CMD_LEN];
    token = strtok(command, " ");
    int arg_count = 0;
    char *output_file = NULL;

    while (token != NULL && arg_count < MAX_CMD_LEN) {
        if (strcmp(token, ">") == 0) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                output_file = token;
            }
            break;
        }
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    if (arg_count > 0) {
        replace_env_vars(args);
        execute_command(paths, args, output_file);
    }

    return EXIT_SUCCESS;
}
