#ifndef __WORLD_H__
#define __WORLD_H__

#include <iostream>
#include <vector>

#include "Tile.h"

template <typename ArrayType>
class DynamicArray {

  static const ELEM_INCREMENT = 64;

  ArrayType data* = nullptr;
  size_t size = 0;

  DynamicArray() {
    data = new ArrayType[ ELEM_INCREMENT ];
  }

public:

  void push( ArrayType datum ) {

    if ( size >= ELEM_INCREMENT ) {
      ArrayType * oldData = data;
    }
  }

  ~DynamicArray() {

  }
};

class World {

  std::vector<Tile> tiles;
  size_t columns;

public:

  World( std::vector<char*> tileChars ) {

    size_t maxCols = 0;

    // Rows
    for ( auto i = tileChars.begin(); i != tileChars.end(); ++i ) {
      // Chars on this row
      for ( size_t j = 0; ( *i )[ j ] != 0; ++j ) {
        Tile tile( ( *i )[ j ] );
        tiles.push_back( tile );
        size_t colNum = j + 1;
        if ( colNum > maxCols )
          maxCols = colNum;
      }
    }

    columns = maxCols;
  }

  void print() {

    auto tile = tiles.begin();
    auto firstTile = tiles.begin();

    for ( ; tile != tiles.end(); ++tile ) {
      std::cout << tile->character;
      std::vector<Tile>::difference_type index = tile - firstTile;
      if ( index % columns == columns - 1 )
        std::cout << std::endl;
    }
  }
};

#endif
