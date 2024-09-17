#include "../include/libs.h"

int sh_crfile(char **args);

int sh_crfile(char **args)
{
    if (args[1] == NULL) {
      fprintf(stderr, "sh: expected argument for \"crfile\" command\n");
      return 1;
    }

    char file_name[1024] = "";

    for (int i = 1; args[i] != NULL; i++) {
      strcat(file_name, args[i]);
      if (args[i + 1] != NULL) {
        strcat(file_name, " ");
      }
    }

    struct stat path_stat;
    if (stat(file_name, &path_stat) == 0 && S_ISDIR(path_stat.st_mode)) {
      fprintf(stderr, "sh: '%s' is a directory\n", file_name);
      return 1;
    }

    FILE *fptr = fopen(file_name, "w");
    if (fptr == NULL) {
      perror("sh: fopen");
      return 1;
    }

    printf("File '%s' created successfully!\n", file_name);

    fclose(fptr);
    return 1;
}