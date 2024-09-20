cd ../
echo Starting AHSH Command Build...
HEADER=include/commands.h
echo -n "" > $HEADER
echo "#ifndef COMMANDS_H" >> $HEADER
echo "#define COMMANDS_H" >> $HEADER
for file in term/*.h
do
    echo "#include \"../$file\"" >> $HEADER
done
echo "#endif" >> $HEADER
echo BUILD FINISHED