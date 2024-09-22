#include "../include/libs.h"

int sh_rename(char **args) {
    if (args[1] == NULL || args[2] == NULL) {
        fprintf(stderr, "sh: expected two arguments for \"rename\" command\n");
        return 1;
    }

    char old_name[1024] = "";
    for (int i = 1; args[i] != NULL && args[i] != args[2]; i++) {
        strcat(old_name, args[i]);
        if (args[i + 1] != args[2]) {
            strcat(old_name, " ");
        }
    }

    char new_name[1024] = "";
    strcat(new_name, args[2]);

    if (rename(old_name, new_name) != 0) {
        perror("sh: rename");
        return 1;
    }

    printf("'%s' renamed to '%s' successfully\n", old_name, new_name);
    return 1;
}