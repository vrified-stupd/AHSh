#include "../include/libs.h"
#include "../include/properties.h"


int sh_ver(char **args);

int sh_ver(char **args)
{
    int i;
    printf("%s", shName);
    printf(" ");
    printf("%s", shVersion);
    printf("\n");

    printf("Name: ");
    printf("%s", name);
    printf("\n");
    return 1;
}