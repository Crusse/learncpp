CC = g++
CCFLAGS = -std=c++11 -I../primer -Wall -Werror=conversion
BUILDDIR = build/

all:
	mkdir -p $(BUILDDIR)
	$(CC) $(CCFLAGS) main.cpp -o $(BUILDDIR)all.out

# target to clean up the object files and any core files
# executing "make clean" in a subdirectory will remove all
# files named core or any file ending in .obj, or .stackdump
clean:
	rm -rf $(BUILDDIR)

