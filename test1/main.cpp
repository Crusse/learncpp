#include <iostream>

struct Tile {
  char character = '.';
};

class World {

public:

  static const int WORLD_WIDTH = 32;
  static const int WORLD_HEIGHT = 16;
  static const int WORLD_SIZE = ( WORLD_WIDTH * WORLD_HEIGHT );

  Tile tiles[ WORLD_WIDTH * WORLD_HEIGHT ] = {};

  void print() {

    for ( size_t i = 0; i < WORLD_SIZE; ++i ) {
      std::cout << this->tiles[ i ].character;
      if ( i % WORLD_WIDTH == WORLD_WIDTH - 1 )
        std::cout << std::endl;
    }
  }
};

int main( int argc, char** argv ) {

  World world;
  
  for ( int i = 1; i < argc && i < World::WORLD_HEIGHT; ++i ) {
    for ( size_t j = 0; argv[ i ][ j ] != 0 && j < World::WORLD_WIDTH; ++j ) {
      Tile tile;
      tile.character = argv[ i ][ j ];
      world.tiles[ i * World::WORLD_WIDTH + j ] = tile;
    }
  }

  world.print();

  return 0;
}


