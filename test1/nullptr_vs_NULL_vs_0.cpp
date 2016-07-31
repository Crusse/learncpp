#include <iostream>
  
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

class MyClass {
public:
	MyClass( int * numPtr ) { std::cout << "Ptr ctor" << std::endl; }
	MyClass( int num ) { std::cout << "Num ctor" << std::endl; }
};

int main( int argc, char ** argv ) {
  
	MyClass obj1 = MyClass( nullptr );
	MyClass obj2 = MyClass( 0 );
	// MyClass obj3 = MyClass( NULL ); // error: call of overloaded ‘MyClass(NULL)’ is ambiguous

	return 0;
}
