#include "functions.h"

int fact( int i ) {

  if ( i > 1 )
    return i * fact( i - 1 );
  return 1;
}

int abs( int i ) {
  return i < 0 ? -i : i;
}