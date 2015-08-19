#include <iostream>
#include <string>
#include <vector>

using namespace std;

int func( int, int );
vector<int (*)( int, int )> vec;

int add( int a, int b ) {
  return a + b;
}
int sub( int a, int b ) {
  return a - b;
}
int mul( int a, int b ) {
  return a * b;
}
int myDiv( int a, int b ) {
  return a / b;
}

int main() {
  
  vec.push_back( add );
  vec.push_back( sub );
  vec.push_back( &mul );
  vec.push_back( &myDiv );

  for ( auto funcPtr : vec )
    cout << (*funcPtr)( 4, 2 ) << endl;
    // cout << funcPtr( 4, 2 ) << endl;

  return 0;
}

