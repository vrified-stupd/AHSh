#include "../include/libs.h"

int sh_pcd(char **args);

int sh_pcd(char **args) {
    char cwd[1024];

    // Get the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current directory: %s\n", cwd);
    } else {
        perror("sh: getcwd");  // Print an error if getcwd fails
    }

    return 1;
}