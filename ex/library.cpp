#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <stack>

using namespace std;

// 8.1, 8.2
istream& outputStream( istream &in ) {

  string str;
  while ( !in.eof() ) {
    in >> str;
    cout << str;
  }
  in.clear();
  return in;
}

// 8.4, 8.5
vector<string> lines;
vector<string> words;
void readLines( const string filename ) {
  
  string line;
  ifstream in( filename );

  while ( getline( in, line ) ) {
    lines.push_back( line );
  }
}
void readWords( const string filename ) {
  
  string wurd;
  ifstream in( filename );

  while ( in >> wurd ) {
    words.push_back( wurd );
  }
}

int main1() {

  outputStream( cin );
  return 0;
}

// 8.4
int main2() {

  readLines( "/home/crusse/.vimrc" );
  for ( auto line : lines )
    cout << "--- " << line << endl;
  return 0;
}

// 8.5
int main3() {

  readWords( "/home/crusse/.vimrc" );
  for ( auto wurd : words )
    cout << "--- " << wurd << endl;
  return 0;
}

// 8.10
int main4() {
  
  vector<string> lines;
  ifstream stream( "X:\\Dropbox\\git\\learncpp\\learn_c.txt" );
  string line;

  while ( getline( stream, line ) ) {
    lines.push_back( line );
  }

  for ( const auto &line : lines ) {
    istringstream stringStream( line );
    string word;
    while ( stringStream >> word )
      cout << word << endl;
  }

  return 0;
}

// 8.11
struct PersonInfo { 
	string name;
	vector<string> phones;
};
int main5() {
  
  string line, word;
  vector<PersonInfo> people;
  istringstream record;

  cout << "Enter name, then space, then space-separated phone numbers. One person per line. End with an EOF (CTRL-Z on Win)" << endl;

  while ( getline( cin, line ) ) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    record.clear();
    people.push_back(info);
  }

  for ( auto & person : people ) {
    cout << person.name << endl;
    for ( auto & phone : person.phones )
      cout << phone << " ";
    cout << endl;
  }

  return 0;
}

// 9.2
list<deque<int>> listOfDequesOfInts;

// 9.5
vector<int>::iterator & findIntInVecRange( vector<int>::iterator &vecBegin, vector<int>::iterator &vecEnd, const int num ) {
  for ( ; vecBegin != vecEnd; vecBegin++ ) {
    if ( *vecBegin == num )
      return vecBegin;
  }
  return vecEnd;
}
int main6() {
  
  vector<int> intVec = { 1, 2, 3, 4, 5 };
  auto iter = findIntInVecRange( intVec.begin(), intVec.end(), 4 );
  if ( iter != intVec.end() )
    cout << "Found " << *iter << endl;
  else
    cout << "Did not find iterator" << endl;
  return 0;
}

// 9.11
vector<int> vec1; // default-initialized (0 outside func, undefined inside func)
vector<int> vec2 = { 1, 2, 3 }; // list-initialized
vector<int> vec3 = vec2; // copy
vector<int> vec4( vec3.begin(), vec3.end() ); // iterator range copy
vector<int> vec5( 10 ); // 10 value-initialized elems
vector<int> vec6( 10, 42 ); // 10 elems initialized with 42

// 9.13
list<int> iList = { 1, 2, 3 };
vector<double> dVec( iList.begin(), iList.end() );
vector<int> iVec = { 1, 2, 3 };
vector<double> dVec2( iVec.begin(), iVec.end() );

// 9.14
int main7() {
  
  list<char*> strList = { "a", "b", "c" };
  vector<string> strVec;
  strVec.assign( strList.begin(), strList.end() );
  for ( auto it = strVec.begin(); it != strVec.end(); it++ )
    cout << *it << endl;
  return 0;
}

// 9.18
int main8() {
  
  string str;
  deque<string> que;
  while ( cin >> str ) {
    que.push_back( str );
  }
  for ( auto it = que.begin(); it != que.end(); ++it ) {
    cout << *it << endl;
  }
  return 0;
}

// 9.19
int main9() {
  
  string str;
  list<string> que;
  while ( cin >> str ) {
    que.push_back( str );
  }
  for ( auto it = que.begin(); it != que.end(); ++it ) {
    cout << *it << endl;
  }
  return 0;
}

// 9.20
int main10() {
  
  list<int> nums = { 1, 2, 3, 4, 5 };
  deque<int> even;
  deque<int> odd;
  for ( auto it = nums.begin(); it != nums.end(); ++it ) {
    if ( *it % 2 == 0 )
      even.push_back( *it );
    else
      odd.push_back( *it );
  }
  return 0;
}

// 9.26
int main11() {
  
  int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
  vector<int> iVec( begin( ia ), end( ia ) );
  list<int> iList( begin( ia ), end( ia ) );
  
  auto it = iList.begin();
  while ( it != iList.end() ) {
    if ( *it % 2 )
      it = iList.erase( it );
    else
      ++it;
  }
  cout << "List, odd removed:" << endl;
  for ( auto val : iList )
    cout << val << endl;

  auto it2 = iVec.begin();
  while ( it2 != iVec.end() ) {
    if ( *it2 % 2 == 0 )
      it2 = iVec.erase( it2 );
    else
      ++it2;
  }
  cout << "Vector, even removed:" << endl;
  for ( auto val : iVec )
    cout << val << endl;

  return 0;
}

// 9.31
int main12() {
  
  list<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  auto iter = vi.begin();
  while ( iter != vi.end() ) {
    if ( *iter % 2 ) {
      iter = vi.insert( iter, *iter );
      iter++;
      iter++;
    }
    else
      iter = vi.erase( iter );
  }

  return 0;
}

// Many memory, such wow
int main13() {
  vector<double> vec = {};
  vec.reserve( 122331111 );
  return 0;
}

// 9.41, 9.42
int main14() {
  
  vector<char> cVec = { 'W', 'a', 't', };
  string str;
  str.reserve( 100 );
  str.assign( cVec.begin(), cVec.end() );
  return 0;
}

// 9.43
void properifyString( string & str, const string oldVal, const string newVal ) {

  deque<char> seenStr;
  auto it = str.begin();

  while ( it != str.end() ) {
    seenStr.push_back( *it );
    if ( seenStr.size() > oldVal.size() )
      seenStr.pop_front();
    if ( seenStr.size() == oldVal.size() ) {
      auto itSeen = seenStr.begin();
      auto itOld = oldVal.begin();
      bool oldValSeen = true;
      for ( ; itSeen != seenStr.end() && itOld != oldVal.end(); ++itSeen, ++itOld ) {
        if ( *itSeen != *itOld ) {
          oldValSeen = false;
          break;
        }
      }
      if ( oldValSeen ) {
        seenStr.clear();
        it = str.erase( it - ( oldVal.size() - 1 ), it + 1 );
        it = str.insert( it, newVal.begin(), newVal.end() ) + newVal.size();
      }
      else
        ++it;
    }
    else
      ++it;
  }
}
// 9.44
void properifyString2( string & str, const string oldVal, const string newVal ) {
  
  for ( string::size_type i = 0; i < str.size(); ) {
    if ( i + oldVal.size() > str.size() )
      break;
    if ( str.substr( i, oldVal.size() ) == oldVal ) {
      str.replace( i, oldVal.size(), newVal );
      i = newVal.size() - 1;
    }
    else
      ++i;
  }
}
int main15() {
  
  string str = "Wut is dis shit";
  properifyString( str, "Wut", "What" );
  properifyString( str, "dis", "this" );
  properifyString( str, "shit", "MANURE" );
  cout << str << endl;
  
  string str2 = "Wut is dis shit";
  properifyString2( str2, "Wut", "What" );
  properifyString2( str2, "dis", "this" );
  properifyString2( str2, "shit", "$#&" );
  cout << str2 << endl;

  return 0;
}

// 9.50
int main16() {
  
  vector<string> vec = { "1", "22", "333" };
  unsigned sum = 0;
  for ( auto str : vec ) {
    cout << str << " ";
    sum += stoi( str );
  }
  cout << " = " << sum << endl;
  
  vector<string> vec2 = { "1.25", "22.14724", "333.87565267885" };
  double sum2 = 0;
  for ( auto str : vec2 ) {
    cout << str << " ";
    sum2 += stod( str );
  }
  cout << " = " << to_string( sum2 ) << endl;

  return 0;
}

// 9.51
class Date {

private:
  unsigned year = 0;
  unsigned month = 0;
  unsigned day = 0;
  static const array<string, 12> months;

public:
  Date( string dateStr ) {
    
    if ( !initAmurricaDate( dateStr ) 
      && !initSuomiDate( dateStr ) 
      && !initUnixDate( dateStr ) )
    {
      cout << "Could not init date from \"" << dateStr << "\"" << endl;
    }
  }

private:

  bool initAmurricaDate( string str ) {
    // Minimum string length: "Jan 1, 1"
    if ( str.size() < 8 )
      return false;
    string strMonth = str.substr( 0, 3 );
    for ( array<string, 12>::size_type i = 0; i < months.size(); ++i ) {
      if ( months[i] == strMonth ) {
        month = i + 1;
        break;
      }
    }
    if ( !month )
      return false;
    string::size_type spacePos = str.find( ' ' );
    if ( spacePos == string::npos )
      return false;
    day = stoi( str.substr( spacePos + 1 ) );
    if ( !day )
      return false;
    string::size_type commaPos = str.find( ',' );
    if ( commaPos == string::npos || commaPos >= str.size() )
      return false;
    year = stoi( str.substr( commaPos + 2 ) );
    if ( !year )
      return false;
    return true;
  }

  bool initSuomiDate( string str ) {
    // Minimum string length: "1.1.1"
    if ( str.size() < 5 )
      return false;
    string::size_type monthIndex = str.find( '.' );
    if ( monthIndex == string::npos )
      return false;
    string::size_type yearIndex = str.find( '.', monthIndex + 1 );
    if ( yearIndex == string::npos )
      return false;
    day = stoi( str );
    month = stoi( str.substr( monthIndex + 1 ) );
    if ( !month )
      return false;
    year = stoi( str.substr( yearIndex + 1 ) );
    if ( !year )
      return false;
    return true;
  }

  // Obviously this is not production-ready...
  // but hey, it supports years before epoch!
  bool initUnixDate( string str ) {
    if ( str.find_first_not_of( "-0123456789" ) != string::npos )
      return false;
    long long timestamp = stoll( str );
    long long daysSinceEpoch = timestamp / 60 / 60 / 24;
    long long yearsSinceEpoch = daysSinceEpoch / 365;
    year = yearsSinceEpoch + 1970;
    double yearProgress = abs( daysSinceEpoch % 365 / 366.0 );
    month = ( yearProgress == 0 )
      ? 1
      : 12 * yearProgress + 1;
    day = ( yearProgress == 0 )
      ? 1
      : 365 * yearProgress / 32 + 1;
    return true;
  }
};

const array<string, 12> Date::months = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

int main17() {
  
  Date date( "Feb 25, 2015" );
  Date date2( "25.2.2015" );
  Date date3( "1424815200" );
  Date date4( "-1424815200" );
  // Test with bad data, too
  Date date5( "Jan 1, " );

  return 0;
}

// 9.52
string replaceParenExprs( const string &str ) {

  stack<char> strStack;
  unsigned parenStarts = 0;

  for ( const auto &val : str ) {
    strStack.push( val );
    if ( val == '(' ) {
      parenStarts++;
    }
    else if ( val == ')' && parenStarts != 0 ) {
      while ( strStack.top() != '(' )
        strStack.pop();
      if ( strStack.top() == '(' )
        strStack.pop();
      strStack.push( '#' );
      parenStarts--;
    }
  }

  string ret( strStack.size(), 0 );
  stack<char>::size_type stackIndex = strStack.size() - 1;

  while ( !strStack.empty() ) {
    ret[ stackIndex ] = strStack.top();
    strStack.pop();
    stackIndex--;
  }

  return ret;
}
int main() {
  
  //string expr = "x - (1 + 61 % (3 + (6 / 3))) * 7 - (x / 2)";
  string expr = "(()(()))()(()";
  //string expr = "))((";
  expr = replaceParenExprs( expr );

  return 0;
}