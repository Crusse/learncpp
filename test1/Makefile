CC = g++
LDFLAGS = -lncurses
CCFLAGS = -std=c++11 -Wall -Werror=conversion
BUILDDIR = build/

all: builddir game tests

builddir:
	mkdir -p $(BUILDDIR)

game: builddir
	$(CC) $(CCFLAGS) -g game/*.cpp -o $(BUILDDIR)game $(LDFLAGS)

tests: builddir
	$(CC) $(CCFLAGS) typedef_tests.cpp -o $(BUILDDIR)typedef_tests $(LDFLAGS)
	$(CC) $(CCFLAGS) nullptr_vs_NULL_vs_0.cpp -o $(BUILDDIR)nullptr_vs_NULL_vs_0 $(LDFLAGS)

# target to clean up the object files and any core files
# executing "make clean" in a subdirectory will remove all
# files named core or any file ending in .obj, or .stackdump
clean:
	rm -rf $(BUILDDIR)

