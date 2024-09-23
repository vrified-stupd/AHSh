# this script only works on linux and not for anything else.

import sys
import os

def install(unstable : str):
    if unstable == "0":
        print("Starting install (Assuming Git is installed)...")
        os.chdir(os.path.expanduser("~"))
        os.system('git clone https://github.com/vrified-stupd/AHSh/ --branch a2.1.0')
        chooseName = input("Choose a name \n>: ")
        properties = open("AHSh/include/properties.h", "w")
        properties.write("#ifndef PROPERTIES_H\n#define PROPERTIES_H\n\n#include \"libs.h\"\n// Shell Properties. Deleting a value/variable can make the shell have segfaults.\n\nchar *shVersion = \"a2.1.1\"; // Shell Version. You can change this.\nchar *name = \""+chooseName+"\"; // SHOULD CHANGE BASED ON THE USER INPUT DURING INSTALLATION\nchar *prefix = \">:\"; // Shell prefix, that sums it up lol\nchar *shName = \"AHSh\"; // Shell name, the name of the shells\n\n#endif") # I'm sorry you had to see this line of code
        properties.close()
        os.chdir("AHSh/buildsh")
        os.system('echo $PWD')
        os.system('sh ./buildcom.sh')
        os.system('make')
        sys.exit(0)
    elif unstable == "1":
        print("Starting install (Assuming Git is installed)...")
        os.chdir(os.path.expanduser("~"))
        os.system('git clone https://github.com/vrified-stupd/AHSh.git')
        chooseName = input("Choose a name \n>: ")
        properties = open("AHSh/include/properties.h", "w")
        properties.write("#ifndef PROPERTIES_H\n#define PROPERTIES_H\n\n#include \"libs.h\"\n// Shell Properties. Deleting a value/variable can make the shell have segfaults.\n\nchar *shVersion = \"a2.1.1\"; // Shell Version. You can change this.\nchar *name = \""+chooseName+"\"; // SHOULD CHANGE BASED ON THE USER INPUT DURING INSTALLATION\nchar *prefix = \">:\"; // Shell prefix, that sums it up lol\nchar *shName = \"AHSh\"; // Shell name, the name of the shells\n\n#endif") # I'm sorry you had to see this line of code
        properties.close()
        os.chdir("AHSh/buildsh")
        os.system('echo $PWD')
        os.system('sh ./buildcom.sh')
        os.system('make')
        sys.exit(0)
    else:
        print("Wow, you got this error! You're dumb! (respectfully)") # You get this error if you're actually stupid


while True:
    unstableInput = input("Choose between unstable and release version of AHSh (0 is release and 1 is unstable) \n>: ")

    if unstableInput == "0":
        install("0")
    elif unstableInput == "1":
        install("1")
    else:
        print("INVALID OPTION")
