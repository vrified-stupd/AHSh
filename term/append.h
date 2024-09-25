#include "../include/libs.h"

int sh_append(char **args);

int sh_append(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "sh: expected at least two arguments for \"write\" command\n");
        return 1;
    }

    FILE *fptr = fopen(args[1], "a");
    if (fptr == NULL) {
        perror("sh: fopen");
        return 1;
    }

    char content[1024] = "";

    for (int i = 2; args[i] != NULL; i++) {
        strcat(content, args[i]);
        if (args[i + 1] != NULL) {
            strcat(content, " ");
        }
    }

    fprintf(fptr, "%s", content);

    fclose(fptr);

    printf("Successfully written to the file '%s'\n", args[1]);
    return 1;
}