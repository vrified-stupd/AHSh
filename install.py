# this script only works on linux and not for anything else.

import sys
import os

def install(unstable : str):
    if unstable == "0":
        print("Starting install (Assuming Git is installed)...")
        os.chdir(os.path.expanduser("~"))
        os.system('git clone https://github.com/vrified-stupd/AHSh/ --branch a2.1.0')
        os.chdir("AHSh/buildsh")
        os.system('echo $PWD')
        os.system('sh ./buildcom.sh')
        os.system('make')
        sys.exit(0)
    elif unstable == "1":
        print("Starting install (Assuming Git is installed)...")
        os.chdir(os.path.expanduser("~"))
        os.system('git clone https://github.com/vrified-stupd/AHSh.git')
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