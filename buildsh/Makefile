ahsh_make:
	echo MAKE
	echo Building Commands...
	sh ./buildcom.sh
	echo Starting x86-64 Compilation...
	gcc -m64 ../ahsh.c -o ../build/ahsh-amd64.elf
	echo Compilation Finished
	echo Starting x86 Compilation...
	gcc -m32 ../ahsh.c -o ../build/ahsh-x86.elf
	echo Compilation Finished