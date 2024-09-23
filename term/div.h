#include "../include/libs.h"

int sh_div(char **args);

int sh_div(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "sh: expected at least one argument for \"div\" command\n");
        return 1;
    }

    char *endptr;

    // Initialize quo with the first number
    double quo = strtod(args[1], &endptr);

    // Check if the first argument is a valid number
    if (*endptr != '\0') {
        fprintf(stderr, "sh: invalid number '%s'\n", args[1]);
        return 1;
    }

    // Loop over the remaining arguments, starting from the second one
    for (int i = 2; args[i] != NULL; i++) {
        // Convert the argument to a double
        double num = strtod(args[i], &endptr);

        // Check if the argument is a valid number
        if (*endptr != '\0') {
            fprintf(stderr, "sh: invalid number '%s'\n", args[i]);
            return 1;
        }

        // Check for division by zero
        if (num == 0.0) {
            fprintf(stderr, "sh: division by zero\n");
            return 1;
        }

        // Perform division
        quo /= num;
    }

    // Print the result
    printf("%.2f\n", quo);  // Display the quotient with two decimal places
    return 1;
}