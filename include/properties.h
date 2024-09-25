#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "libs.h"
// Shell Properties. Deleting a value/variable can make the shell have segfaults.

char *shVersion = "a2.1.1"; // Shell Version. You can change this.
char *name = "TEST NAME"; // SHOULD CHANGE BASED ON THE USER INPUT DURING INSTALLATION
char *prefix = ">:"; // Shell prefix, that sums it up lol
char *shName = "AHSh"; // Shell name, the name of the shells
char *usesTerm = "1";  // Check if this shell has a terminal, 0 is no, 1 is yes. Anything else will default to shell (DOES NOTHING FOR NOW)

#endif