#include <iostream>
#include <vector>
#include "ncurses.h"

#include "World.h"
#include "Tile.h"

int main( int argc, char** argv ) {

  World world( std::vector<char*>( argv + 1, argv + argc ) );
  world.print();

  return 0;
}


