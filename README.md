# AHSh

Advanced Hybrid Shell or AHSh for short, is a simple shell that you can use on Linux or port to an OS you made. I made this shell out of spite because my friend said "needs more work" to some shell commands I made for them.

## Why???

"Why does this exist?" you might ask, well, I (stupd) am designing this shell for AHK which you could find [here](https://github.com/Libre-X-Project/AHK-main). You might also ask "Why do I need this?", the thing is, you don't! This shell caters to a specific group of people (osdevs and hobbyists) and not the average consumer.

## How to run AHSh?

To run AHSh, you could download a release and run the elf through a terminal (boring) or you could compile it in your Linux system (not boring). These instructions will help you compile AHSh, not download a release! If you don't want to do this process, download the elf at the release branch you want. You could also run `wget -O install.py https://raw.githubusercontent.com/vrified-stupd/AHSh/refs/heads/main/install.py && python3 install.py` to automatically do the compiling for you. (You still have to download the dependancies below to use/compile AHSh)

### Pre-requisites

- libc6-dev-i386
- GCC 12.2 or Above (Older versions may work but are untested)

### Installation

#### Step 1

Open your Linux Terminal and type:

```
git clone https://github.com/vrified-stupd/AHSh.git
```

This will clone the repo into your system.

#### Step 2

Type:

```
cd AHSh/buildsh
```

This will change your directory to where the compile files are.

#### Step 3

You want to build all the commands first if you want the full experience. If not, then you could skip this step. Type:

```
chmod +x buildcom.sh
./buildcom.sh
```

##### For x86 machines

Run this compile script:

```
chmod +x build32.sh
./build32.sh
```

##### For x86_64

Run this compile script:

```
chmod +x build64.sh
./build64.sh
```

#### Step 4

Now you can run AHSh without any errors (I hope...) by typing running the file via terminal.

## How to replace bash with this in Linux (idk why you would do this lmao)

### Step 1

Open ".bashrc" with any text editor, this file is located in your home folder and is a hidden file.

### Step 2

Go to the end of the file and type:

```
./path/to/ahsh/elf
```

Make sure to change "path/to/ahsh/elf" to the path of the elf file (common sense lol).

###

Save and everytime you open the terminal, you should be running AHSh!

If you want to revert back to bash, just remove the line you added and save, everything will revert back to normal.
