#include <iostream>

int main( int argc, char** argv ) {

  typedef int numero;
  numero i = 2;
  typedef numero *pnum;
  pnum pi = &i;
  const pnum cpi = &i; // const pointer to int, _not_ pointer to const int; const always modifies the _base type_ (here ptr-to-int)
  
  std::cout << ( i + *pi + *cpi ) << std::endl;

  return 0;
}

