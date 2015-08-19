#include <iostream>
#include <string>

using namespace std;

// 6.46
inline constexpr bool isShorter( const string &str1, const string &str2 ) {
  return str1.size() < str2.size();
}

int main() {
  
  if ( isShorter( "blaaaa", "blöö" ) )
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
