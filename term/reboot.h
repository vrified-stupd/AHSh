#include "../include/libs.h"
#include "../ahsh.h"

int sh_reboot(char **args);

int sh_reboot(char **args)
{
    printf("Reboot!\n");
    system("clear");
    info();
}