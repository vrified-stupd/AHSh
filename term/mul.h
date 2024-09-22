#include "../include/libs.h"

int sh_mul(char **args);

int sh_mul(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "sh: expected at least one argument for \"mul\" command\n");
        return 1;
    }

    double pro = 0.0;

    for (int i = 1; args[i] != NULL; i++) {
        char *endptr;

        // Convert string to double
        double num = strtod(args[i], &endptr);

        // Check if the entire string was converted
        if (*endptr != '\0') {
            fprintf(stderr, "sh: invalid number '%s'\n", args[i]);
            return 1;
        }

        pro *= num;
    }

    printf("%.2f\n", pro);  // Display the sum with two decimal places
    return 1;
}