#ifndef __TILE_H__
#define __TILE_H__

class Tile {

public:

  char character = '.';

  Tile() = default;
  Tile( char character ) : character( character ) {}
};

#endif
