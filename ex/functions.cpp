
#include <iostream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

int main1() {
  // 6.3
  cout << fact( 4 ) << endl;
  return 0;
}

int main2() {
  // 6.5
  cout << abs( 2 ) << endl;
  cout << abs( -2 ) << endl;
  return 0;
}

int increment() {
  static int i = 0;
  return i++;
}

int main3() {
  // 6.7
  cout << increment() << endl;
  cout << increment() << endl;
  cout << increment() << endl;
  return 0;
}

void swapInts( int *int1, int *int2 ) {
  int temp = *int1;
  *int1 = *int2;
  *int2 = temp;
}

void swapIntsRef( int &int1, int &int2 ) {
  int temp = int1;
  int1 = int2;
  int2 = temp;
}

int main4() {
  // 6.10
  int int1 = 1;
  int int2 = 2;
  swapInts( &int1, &int2 );
  cout << "int1: " << int1 << endl;
  cout << "int2: " << int2 << endl;
  // 6.12
  swapIntsRef( int1, int2 );
  cout << "int1: " << int1 << endl;
  cout << "int2: " << int2 << endl;
  return 0;
}

void printArrAddress( char arr[] /* or char *arr */ ) {
  cout << "ptr: " << &arr << " (size " << sizeof(arr) << ")" << endl;
}
void printArrRefAddress( char (&arr)[10] ) {
  cout << "ptr: " << &arr << " (size " << sizeof(arr) << ")" << endl;
}
void printArrPtrAddress( char (*arr)[10] ) {
  cout << "ptr: " << &arr << " (size " << sizeof(arr) << ")" << endl;
}

int main5() {
  // Array vs pointer-to-first-element
  char arr[10] = {};
  printArrAddress( arr );
  printArrRefAddress( arr );
  printArrPtrAddress( &arr );
  return 0;
}

int retLargerInt( int i, const int * pi ) {
  if ( i < *pi )
    return *pi;
  return i;
}

int main6() {
  // 6.21
  int i = 5;
  int larger = retLargerInt( 2, &i );
  cout << larger << endl;
  return 0;
}

void swapIntPtrs( int *&i, int *&j ) {
  int *temp = i;
  i = j;
  j = temp;
}

int main7() {
  // 6.22
  int i = 5, j = 10;
  int *pi = &i, *pj = &j;
  swapIntPtrs( pi, pj );
  cout << "i:" << *pi << ", j:" << *pj << endl;
  return 0;
}

void print( const int ia[10] ) {
  for ( size_t i = 0; i < 10; ++i ) {
    cout << ia[i] << endl;
  }
}

int main8() {
  // 6.24
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  print( arr );
  return 0;
}

int main9( int argc, char **argv ) {
  // 6.25
  string out;
  for ( auto str : vector<string>( argv + 1, argv + argc ) )
    out += str;
  cout << out << endl;
  return 0;
}

void testParamListInit( vector<string> vec ) {
  for ( auto str : vec )
    cout << str << endl;
}

int main10( int argc, char **argv ) {
  testParamListInit( { "what ", "is ", "this?"} );
  return 0;
}

bool str_subrange( const string &str1, const string &str2 ) {
  
  if ( str1.size() == str2.size() )
    return str1 == str2;
  auto size = ( str1.size() <= str2.size() )
    ? str1.size()
    : str2.size();
  for ( decltype( size ) i = 0; i < size; ++i ) {
    if ( str1[i] != str2[i] )
      return false;
  }

  return true;
}

int main11( int argc, char **argv ) {
  // 6.30
  bool test = str_subrange( "bla", "blöö" );
  return 0;
}

void printVectorRecur( const vector<string> &vec, vector<string>::size_type index = 0 ) {
  
  if ( index + 1 > vec.size() )
    return;
  cout << vec[ index ] << endl;
  printVectorRecur( vec, index + 1 );
}

int main12( int argc, char **argv ) {
  // 6.33
  printVectorRecur( { "yks", "kaks", "koli" } );
  return 0;
}

// 6.36
// string (&func636())[10];

// 6.37
/*
typedef string (&arrRef)[10];
arrRef func637_1();
auto func637_2() -> string(&)[10];
string (&arr)[10];
decltype( arr ) func637_3();
*/

// 6.38
int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) &arrRefFunc(int i) {
  return (i % 2) ? odd : even;
}
int main13( int argc, char **argv ) {
  int *res = arrRefFunc( 1 );
  return 0;
}

// Func that takes a pointer to an array of 10 ints, and returns a pointer to an array of 10 ints
int (*funcc(int (* const i)[10]))[10] {
  return i;
}
int (*(*funcPtr)(int (*)[10]))[10] = funcc;

int (*myPtr())(int);

// 6.54
int func654(int, int);
//std::vector<decltype(func654)> funcsVec;
// or
typedef int (*Func654_t)(int, int);
std::vector<Func654_t> funcsVec;

// 6.55
int add655(int a, int b) { return a + b; }
int sub655(int a, int b) { return a - b; }
int mul655(int a, int b) { return a * b; }
int div655(int a, int b) { return a / b; }

int main14() {
  funcsVec.push_back(add655);
  funcsVec.push_back(sub655);
  funcsVec.push_back(mul655);
  funcsVec.push_back(div655);
  // 6.56
  for ( auto i = funcsVec.begin(); i != funcsVec.end(); ++i )
    cout << (*i)(4, 2) << endl;
  return 1;
}


