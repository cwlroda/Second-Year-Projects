# -------- Variables --------
TARGET=bin/main

OBJECTS=bin/account.o $(TARGET).o

INPUT_DATA=data/accounts.txt

# -------- Compiler --------
CC=g++
CCFLAGS=-Wall -std=c++11

# -------- Compiling options --------
INCFLAGS=-I ./include
#LIBFLAGS=-L ./lib

# -------- Compiling --------
bin/%.o : src/%.cpp
	$(CC) $(CCFLAGS) $(INCFLAGS) -c $< -o $@

# -------- Linking --------
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

#note: if using an external library, placed in folder lib/, then use the variable LIBFLAGS
#$(CC) $(LIBFLAGS) $(OBJECTS) -o bin/$(TARGET)


# -------- Running --------
run:
	./$(TARGET) $(INPUT_DATA)

# -------- Cleaning --------
clean:
	rm bin/*.o $(TARGET)


###########################
# Documentation/Reminders #
###########################
# file name: either makefile or Makefile
# (not Make, nor Makefile.txt, nor Makefile.mk nor Makefile.mak etc...)
#
#
#Format of a rule:
#
#target: dependency(ies)
#[TAB]	command(s)
#
#(the second line has to start with a TABULATION)
#
#Warning about TAB:
#when copying/pasting from a PDF file e.g, re-check ALL the tabulations
#
#
#User-defined variables:
#definition: VAR_NAME=value
#use: $(VAR_NAME)
#
#
#Built-in variables:
#'$@' the target name
#'$<' the first dependency
#'$^' list of all the dependencies (including $<)