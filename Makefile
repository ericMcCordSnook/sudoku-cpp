# Eric McCord-Snook
# This Makefile shows how to link assembly with C++

# Defines the C++ compiler we'll be using
CXX	= clang++

# The different flags we want to use
CXXFLAGS= -std=c++11 -g -O2
# All of the .o files for our program
OFILES	= BoardCell.o Board.o sudoku.o

# This tells make to create a .o file from a .c file, using the
# defaults above (i.e. the CXX and CXXFLAGS macros)
.SUFFIXES: .o .cpp

# How to compile our final program.  Note that we do NOT specify an
# output executable name -- in order for this to work with the grading
# system, the file needs to be a.out (a.exe in Cygwin).
main:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(OFILES)

# This will clean up (remove) all our object files.  The -f option
# tells rm to forcibly remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	/bin/rm -f *.o *~ *# a.out

# We don't have any dependencies for this small program
