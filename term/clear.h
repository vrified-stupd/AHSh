#include "../include/libs.h"

int sh_clear(char **args);

void clearScreen()
{
	const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}


int sh_clear(char **args) {
  clearScreen();
}