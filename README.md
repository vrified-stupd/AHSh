# AHSh

Advanced Hybrid Shell or AHSh for short, is a simple shell that you can use on Linux or port to an OS you made.

## Why???

"Why does this exist?" you might ask, well, I (stupd) am designing this shell for AHK which you could find [here](https://github.com/Libre-X-Project/AHK-main). You might also ask "Why do I need this?", the thing is, you don't! This shell caters to a specific group of people (osdevs) and not the average consumer.

## How to run AHSh?

To run AHSh, you could download a release and run the elf through a terminal (boring) or you could compile it in your Linux system (not boring). These instructions will help you compile AHSh, not download a release!

### Step 1

Open your Linux Terminal and type:

```
git clone https://github.com/vrified-stupd/AHSh.git
```

This will clone the repo into your system.

### Step 2

Type:

```
cd AHSh\buildsh
```

This will change your directory to where the compile files are.

### Step 3

You want to build all the commands first if you want the full experience. If not, then you could skip this step. Type:

```
chmod +x buildcom.sh
./buildcom.sh
```

When you are done building the commands, run the compile script (x86 ONLY!!! x86_64 will come soon and ARM64 is a possibility):

```
chmod +x build32.sh
./build32.sh
```
### Step 4

Now you can run AHSh without any errors (I hope...) by typing:

```
cd ../
./ahsh.elf
```
