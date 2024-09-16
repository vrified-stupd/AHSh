#include "../include/libs.h"

int sh_crfile(char **args);

int sh_crfile(char **args)
{
	if (args[1] == NULL) {
    fprintf(stderr, "sh: expected argument for \"crfile\" command\n");
    return 1;
  }
	else {
		FILE *fptr;
		
		int i = 1;

		fptr = fopen(args[i], "w");

		printf("File successfully made!\n");

		fclose(fptr);
	}
  return 1;
}