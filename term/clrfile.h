#include "../include/libs.h"

int sh_clrfile(char **args);

int sh_clrfile(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "sh: expected argument for \"clrfile\" command\n");
        return 1;
    }

    FILE *fptr = fopen(args[1], "w");
    if (fptr == NULL) {
        perror("sh: fopen");
        return 1;
    }

    fprintf(fptr, "%s\n", "");

    fclose(fptr);
    return 1;
}