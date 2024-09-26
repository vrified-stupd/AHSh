#include "../include/libs.h"

int sh_move(char **args);

int sh_move(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "sh: expected source and destination arguments for \"move\" command\n");
        return 1;
    }

    // Check if the destination is a directory
    struct stat statbuf;
    if (stat(args[2], &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
        // Construct the new file path in the destination directory
        char new_path[1024];
        snprintf(new_path, sizeof(new_path), "%s/%s", args[2], strrchr(args[1], '/') ? strrchr(args[1], '/') + 1 : args[1]);

        // Attempt to rename (move) the file
        if (rename(args[1], new_path) != 0) {
            perror("sh: rename");
            return 1;
        }

        printf("Successfully moved '%s' to '%s'\n", args[1], new_path);
    } else {
        // Attempt to rename (move) the file to a new file path
        if (rename(args[1], args[2]) != 0) {
            perror("sh: rename");
            return 1;
        }

        printf("Successfully moved '%s' to '%s'\n", args[1], args[2]);
    }

    return 1;
}