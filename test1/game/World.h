#ifndef __WORLD_H__
#define __WORLD_H__

#include <iostream>
#include <vector>

#include "Tile.h"
#include "DynamicArray.h"

class World {

  DynamicArray<Tile> tiles;
  size_t columns;

public:

  World( std::vector<char*> tileChars ) {

    size_t maxCols = 0;

    // Rows
    for ( auto i = tileChars.begin(); i != tileChars.end(); ++i ) {
      // Chars on this row
      for ( size_t j = 0; ( *i )[ j ] != 0; ++j ) {
        tiles.push( Tile( ( *i )[ j ] ) );
        size_t colNum = j + 1;
        if ( colNum > maxCols )
          maxCols = colNum;
      }
    }

    // TODO: pad short rows with dots in missing columns

    columns = maxCols;
  }

  void print() {

    for ( size_t i = 0; i < tiles.length(); ++i ) {
      std::cout << tiles[ i ].character;
      if ( i % columns == columns - 1 )
        std::cout << std::endl;
    }
  }
};

#endif

