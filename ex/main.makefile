#g++ compiler: options

# -std=c++0x enables ISO C++ 11 standard
# -I.. pulls in the Version_test.h file for conditional compilation
#      of code the uses features that might not yet be implemented
CC = g++
CCFLAGS = -std=c++11 -I../primer -Wall

# Some programs include headers defined in earlier chapters
# LOCFLAGS used to set tell the compiler where to find a
# header that is not in the same directory as the source file itself
# LOCFLAGS will be set in directory level makefiles as needed
LOCFLAGS =

####### To compile without using a makefile
# To compile an object file from a source file you could execute
# g++ -std=c++0x -c filename.cc # produces filename.obj
# To compile an executable file from an object file, you would execute
# g++ -std=c++0x filename.o      # produces filename.exe
# To compile an executable file from a source file, you would execute
# g++ -std=c++0x filename.cc    # produces filename.exe
#######

all:
	$(CC) $(CCFLAGS) $(LOCFLAGS) *.cc -o all.out

# rule that says how to make a .o object file from a .cc source file
# for a given source file in a given directory you could compile it
# into an object file by executing "make filename.o"

# $< and $@ are macros defined by make
#     $< refers to the file being processed (i.e., compiled or linked)
#     $@ refers to the generated file
%.o: %.cc 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -c $< -o $@

# rule that says how to make a .exe executable file from a .o object file
%.exe: %.o 
	$(CC) $(CCFLAGS) $(LOCFLAGS) $< -o $@

%: %.cc
	$(CC) $(CCFLAGS) $(LOCFLAGS) $< -o $@

# target to clean up the object files and any core files
# executing "make clean" in a subdirectory will remove all
# files named core or any file ending in .obj, or .stackdump
clean:
	rm -rf *.o core *.stackdump

# target to remove executable files as well as object and core files
clobber: clean
	rm -rf *.exe 
