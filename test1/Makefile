CC = g++
LDFLAGS = -lncurses
CCFLAGS = -v -std=c++11 -Wall -Werror=conversion
BUILDDIR = build/

all:
	mkdir -p $(BUILDDIR)
	$(CC) $(CCFLAGS) main.cpp -o $(BUILDDIR)all.out $(LDFLAGS)

# target to clean up the object files and any core files
# executing "make clean" in a subdirectory will remove all
# files named core or any file ending in .obj, or .stackdump
clean:
	rm -rf $(BUILDDIR)

