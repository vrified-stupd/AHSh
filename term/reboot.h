#include "../include/libs.h"

int sh_reboot(char **args);

int sh_reboot(char **args)
{
    printf("Reboot!\n");
    system("clear");
    main(NULL, NULL);
}