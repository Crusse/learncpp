#include <iostream>
#include <string>
#include <vector>
#include "Sales_item.h"

using std::istream;
using std::ostream;
using std::cout;
using std::cin;
using std::string;
using std::vector;

// 7.1
struct SalesData {
  std::string bookNo;
  unsigned unitsSold = 0;
  double revenue = 0;
};
int main15() {
  
  SalesData total;

  if ( std::cin.good() ) {
    while ( std::cin.good() ) {
      
      std::string bookNo;
      unsigned unitsSold;
      double price;
      std::cin >> bookNo >> unitsSold >> price;

      if ( bookNo.empty() )
        continue;

      if ( !total.bookNo.empty() && bookNo != total.bookNo ) {
        std::cout << total.bookNo << " " << total.unitsSold << " " << total.revenue << std::endl;
        total.bookNo = bookNo;
        total.unitsSold = unitsSold;
        total.revenue = ( unitsSold * price );
      }
      else {
        total.bookNo = bookNo;
        total.unitsSold += unitsSold;
        total.revenue += ( unitsSold * price );
      }
    }
    // Last one
    std::cout << total.bookNo << " " << total.unitsSold << " " << total.revenue << std::endl;
  }
  else {
    std::cout << "No data given" << std::endl;
  }

  return 0;
}

// 7.2, 7.21
struct SalesData2 {
  
  friend istream & readSalesData( istream & in, SalesData2 & salesData );
  friend ostream & printSalesData( ostream & out, const SalesData2 & salesData );

private:
  std::string bookNo;
  unsigned unitsSold = 0;
  double revenue = 0;

public:
  // 7.11, 7.38
  SalesData2( const std::string & bookNo ): bookNo( bookNo ) {}
  SalesData2( const std::string & bookNo, const unsigned unitsSold, const double revenue ):
    bookNo( bookNo ), unitsSold( unitsSold ), revenue( revenue ) {}
  SalesData2( istream & in = std::cin ) {
    double price = 0;
    in >> bookNo;
    in >> unitsSold;
    in >> price;
    revenue = unitsSold * price;
  }

  std::string isbn() const {
    return bookNo;
  }
  SalesData2 & combine( const SalesData2 & otherSalesData ) {
    unitsSold += otherSalesData.unitsSold;
    revenue += otherSalesData.revenue;
    return *this;
  }
  double avgPrice() const;
};
// 7.26
inline double SalesData2::avgPrice() const {
  if ( unitsSold )
    return revenue / unitsSold;
  return 0;
}

// 7.3
int main16() {
  /*
  SalesData2 total;

  if ( std::cin.good() ) {
    
    // First one
    std::cin >> total.bookNo >> total.unitsSold >> total.revenue;
    total.revenue = total.unitsSold * total.revenue;
    
    while ( std::cin.good() ) {
      
      SalesData2 salesData;
      std::cin >> salesData.bookNo >> salesData.unitsSold >> salesData.revenue;
      salesData.revenue = salesData.unitsSold * salesData.revenue;
      if ( !salesData.unitsSold )
        continue;
      
      if ( salesData.isbn() != total.isbn() ) {
        std::cout << total.isbn() << " " << total.unitsSold << " " << total.revenue << std::endl;
        total = salesData;
      }
      else {
        total = total.combine( salesData );
      }
    }
    // Last one
    std::cout << total.isbn() << " " << total.unitsSold << " " << total.revenue << std::endl;
  }
  else {
    std::cout << "No data given" << std::endl;
  }
  */
  return 0;
}

// 7.4, 7.5, 7.22
struct Person {

private:
  std::string name;
  std::string address;

public:
  // 7.15
  Person(): name(""), address("") {}
  Person( std::string name ): name( name ), address( "" ) {}
  Person( std::string name, std::string address ): name( name ), address( address ) {}

  // These are const methods so that they're usable with a const Person, 
  // and because they are getters (not setters) which means that they shouldn't modify the object
  std::string getName() const {
    return name;
  }
  std::string getAddress() const {
    return address;
  }

  // 7.9
  istream & read( istream & in ) {
    return in >> name >> address;
  }
  ostream & print( ostream & out ) {
    return out << name << " " << address;
  }
};

// 7.6
SalesData2 addSalesData( const SalesData2 & lhs, const SalesData2 & rhs ) {
  SalesData2 ret;
  ret = lhs;
  ret.combine( rhs );
  return ret;
}
istream & readSalesData( istream & in, SalesData2 & salesData ) {
  double price = 0;
  in >> salesData.bookNo;
  in >> salesData.unitsSold;
  in >> price;
  salesData.revenue = salesData.unitsSold * price;
  return in;
}
ostream & printSalesData( ostream & out, const SalesData2 & salesData ) {
  return out << salesData.isbn() << " " << salesData.unitsSold << " " << salesData.revenue << " " << salesData.avgPrice();
}

// 7.7
int main17() {
  
  SalesData2 total;

  if ( std::cin.good() ) {
    
    // First one
    readSalesData( std::cin, total );
    
    while ( std::cin.good() ) {
      
      SalesData2 salesData;
      readSalesData( std::cin, salesData );
      if ( salesData.isbn().empty() )
        continue;
      
      if ( salesData.isbn() != total.isbn() ) {
        printSalesData( std::cout, total ) << std::endl;
        total = salesData;
      }
      else {
        total = total.combine( salesData );
      }
    }
    // Last one
    printSalesData( std::cout, total ) << std::endl;
  }
  else {
    std::cout << "No data given" << std::endl;
  }

  return 0;
}

// 7.13
int main18() {

  if ( std::cin.good() ) {
  
    // Initialize with data from first line
    SalesData2 total( std::cin );
    
    while ( std::cin.good() ) {
      
      SalesData2 salesData( std::cin );

      if ( salesData.isbn().empty() )
        continue;
      
      if ( salesData.isbn() != total.isbn() ) {
        printSalesData( std::cout, total ) << std::endl;
        total = salesData;
      }
      else {
        total = total.combine( salesData );
      }
    }
    // Last one
    printSalesData( std::cout, total ) << std::endl;
  }
  else {
    std::cout << "No data given" << std::endl;
  }

  return 0;
}

// 7.23, 7.24
// 7.25: we can use synthesized versions of copy and assignment, because we only use member vars.
class Screen {
  
  friend class ScreenMgr;

public:
  typedef std::string::size_type pos;

private:
  pos cursor = 0;
  pos width = 0;
  pos height = 0;
  std::string contents;

public:
  Screen(): cursor(0), width(0), height(0) {}
  Screen( pos w, pos h ): width(w), height(h), contents( w * h, ' ' ) {}
  Screen( pos w, pos h, char c ): width(w), height(h), contents( w * h, c ) {}

  char get() const;
  char get( pos w, pos h ) const;

  Screen &move( pos row, pos col );

  // 7.27
  Screen &set( char c );
  Screen &set( pos w, pos h, char c );

  const Screen &display( ostream &os ) const;
  Screen &display( ostream &os );

private:
  void printToOStream( ostream &os ) const;
};

char Screen::get() const {
  if (cursor + 1 <= width * height)
    return contents[cursor];
  return '\0';
}
char Screen::get( pos w, pos h ) const {
  if ((w + 1) * (h + 1) <= width * height)
    return contents[w * h];
  return '\0';
}
Screen &Screen::move( pos row, pos col ) {
  pos w = row * width;
  pos pos = row + col;
  if ( pos + 1 <= width * height )
    cursor = pos;
  return *this;
}
// 7.27
Screen &Screen::set( char c ) {
  if (cursor + 1 <= width * height)
    contents[cursor] = c;
  return *this;
}
Screen &Screen::set( pos w, pos h, char c ) {
  if ((w + 1) * (h + 1) <= width * height)
    contents[cursor] = c;
  return *this;
}
const Screen &Screen::display( ostream &os ) const {
  printToOStream( os );
  return *this;
}
Screen &Screen::display( ostream &os ) {
  printToOStream( os );
  return *this;
}
void Screen::printToOStream( ostream &os ) const {
  std::string output;
  for ( std::string::size_type i = 0; i < contents.length(); ++i ) {
    if ( i != 0 && i % width == 0 )
      os << "\n";
    os << contents[i];
  }
}

// 7.32
class ScreenMgr {
  
private:
  // We use a shitty syntax because of VS 2013. http://stackoverflow.com/questions/24518192/in-class-member-initializer-fails-with-vs-2013
  std::vector<Screen> screens = {{Screen(24, 80, ' ')}};

public:
  typedef std::vector<Screen>::size_type ScreenIndex;
  void clear( ScreenIndex index );
};

void ScreenMgr::clear( ScreenIndex index ) {
  Screen &screen = screens[ index ];
  screen.contents = std::string( screen.width * screen.height, ' ' );
}

// 7.27
int main19() {
  
  Screen myScreen(5, 5, 'X');
  myScreen.move(4,0).set('#').display(std::cout);
  std::cout << "\n\nTesting if above line returned a copy or ref\n\n";
  myScreen.display(std::cout);
  std::cout << "\n";
  return 0;
}

// 7.31
class Y; // forward declaration
class X {
  Y *ptrToY = 0; // a pointer; data does not live in this class, but somewhere else in memory
};
class Y {
  X objX; // data lives here, in memory; this is not a pointer
};

// 7.40
class Book {
  
private:
  string title;
  int pageCount = 0;
  string author;
  string isbn;

public:
  Book() = default;
  Book( string title, int pageCount = 0, string isbn = "", string author = "" ):
    title(title), pageCount(pageCount), author(author), isbn(isbn) {}
};

int main() {
  
  cout << "test" << std::endl;
  return 0;
}

// 7.43
struct NoDefault {
  int var = 0;
  NoDefault( int i ): var(i) {}
};
struct C {
  NoDefault var;
  C(): var(0) {}
};
C cClass;
//vector<NoDefault> vec(10);
//vector<C> vec(10);

// 7.57
class Account {

private:
  std::string owner;
  double amount = 0;
  static double interestRate;

public:
  void calculate() {
    amount += amount * interestRate;
  }
  static double rate() { return interestRate; }
  static void rate( double newRate ) {
    interestRate = newRate;
  }
  static double initRate() {
    interestRate = 123;
  }
};

double Account::interestRate = initRate();


