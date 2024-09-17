#include "../include/libs.h"

int sh_crdir(char **args);

int sh_crdir(char **args)
{
	if (args[1] == NULL) {
		fprintf(stderr, "sh: expected argument for \"crdir\" command\n");
		return 1;
	}
	else{
		char dir_name[1024] = "";

		for (int i = 1; args[i] != NULL; i++) {
		strcat(dir_name, args[i]);
		if (args[i + 1] != NULL) {
			strcat(dir_name, " ");
		}
		}

		int result = mkdir(dir_name, 0777);
		if (result == 0) {
		printf("Directory '%s' created successfully\n", dir_name);
		} else {
		perror("sh: mkdir");
		}
		return 1;
	}
}