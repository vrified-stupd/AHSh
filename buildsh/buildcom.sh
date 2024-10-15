cd ../
echo Starting AHSH Command Build...
HEADER=include/commands.h
echo -n "" > $HEADER
echo "#ifndef COMMANDS_H" >> $HEADER
echo "#define COMMANDS_H" >> $HEADER
for file in term/*.h
do
    echo "Adding $file"
    echo "#include \"../$file\"" >> $HEADER
    echo "Added $file"
done
echo "#endif" >> $HEADER
echo BUILD FINISHED