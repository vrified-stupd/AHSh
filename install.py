# this script only works on linux and not for anything else.

import sys
import os
version = ""

def install(unstable : str):
    if unstable == "0":
        print("Starting install (Assuming Git is installed)...")
        os.chdir(os.path.expanduser("~"))
        os.system("git clone https://github.com/vrified-stupd/AHSh/ --branch "+version)
        chooseName = input("Choose a name \n>: ")
        properties = open("AHSh/include/properties.h", "w")
        properties.write("#ifndef PROPERTIES_H\n#define PROPERTIES_H\n\n#include \"libs.h\"\n// Shell Properties. Deleting a value/variable can make the shell have segfaults.\n\nchar *shVersion = \""+version+"\"; // Shell Version. You can change this.\nchar *name = \""+chooseName+"\"; // SHOULD CHANGE BASED ON THE USER INPUT DURING INSTALLATION\nchar *prefix = \">:\"; // Shell prefix, that sums it up lol\nchar *shName = \"AHSh\"; // Shell name, the name of the shells\n\n#endif") # I'm sorry you had to see this line of code
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
        properties.write("#ifndef PROPERTIES_H\n#define PROPERTIES_H\n\n#include \"libs.h\"\n// Shell Properties. Deleting a value/variable can make the shell have segfaults.\n\nchar *shVersion = \""+version+"\"; // Shell Version. You can change this.\nchar *name = \""+chooseName+"\"; // SHOULD CHANGE BASED ON THE USER INPUT DURING INSTALLATION\nchar *prefix = \">:\"; // Shell prefix, that sums it up lol\nchar *shName = \"AHSh\"; // Shell name, the name of the shells\n\n#endif") # I'm sorry you had to see this line of code
        properties.close()
        os.chdir("AHSh/buildsh")
        os.system('echo $PWD')
        os.system('sh ./buildcom.sh')
        os.system('make')
        sys.exit(0)
    else:
        print("Wow, you got this error! You're dumb! (respectfully)") # You get this error if you're actually stupid


while True:
    unstableInput = input("Choose between unstable and release version of AHSh (0 is release, 1 is unstable, and 2 is exit) \n>: ")

    if unstableInput == "0":
        version = input("Input your desired version. (e.g, a2.0.0, a1.0.0) \n>: ")
        install("0")
    elif unstableInput == "1":
        install("1")
    elif unstableInput == "2":
        sys.exit(0)
    else:
        print("INVALID OPTION")