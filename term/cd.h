#include "../include/libs.h"

int sh_cd(char **args);

// Function to change the current directory
int sh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "sh: expected argument for \"cd\" command\n");
        return 1;
    }

    // Change the directory
    if (chdir(args[1]) != 0) {
        perror("sh: cd");
        return 1;
    }

    return 1;
}