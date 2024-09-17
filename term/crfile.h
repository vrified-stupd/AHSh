#include "../include/libs.h"

int sh_crfile(char **args);

int sh_crfile(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "sh: expected argument for \"crfile\" command\n");
    return 1;
  }

  struct stat path_stat;
  if (stat(args[1], &path_stat) == 0 && S_ISDIR(path_stat.st_mode)) {
    fprintf(stderr, "sh: '%s' is a directory with the same name\n", args[1]);
    return 1;
  }

  FILE *fptr = fopen(args[1], "w");
  if (fptr == NULL) {
    perror("sh: fopen");
    return 1;
  }

  printf("File '%s' created successfully!\n", args[1]);

  fclose(fptr);
  return 1;
}