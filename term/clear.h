#include "../include/libs.h"

int sh_clear(char **args);


int sh_clear(char **args) {
  	system("clear");
	return 1;
}