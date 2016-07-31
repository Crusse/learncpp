#ifndef __DYNAMIC_ARRAY_H__
#define __DYNAMIC_ARRAY_H__

#include <iostream>

#define DYNAMIC_ARRAY_INCREMENT 64

template <typename ArrayType>
class DynamicArray {

  ArrayType* data = nullptr;
  size_t dataLength = 0;
  size_t size = DYNAMIC_ARRAY_INCREMENT;

  void setSize( size_t newSize ) {

#if ! NDEBUG
    std::cout << "New size: " << newSize << std::endl;
#endif
    
    size_t copyLen = ( newSize < dataLength )
      ? newSize
      : dataLength;

    ArrayType* oldData = data;
    data = new ArrayType[ newSize ];
    size = newSize;

    for ( size_t i = 0; i < copyLen; ++i ) {
      data[ i ] = oldData[ i ];
    }

    dataLength = copyLen;

    delete[] oldData;
  }

public:

  DynamicArray() {
    data = new ArrayType[ DYNAMIC_ARRAY_INCREMENT ];
  }

  size_t length() const {
    return dataLength;
  }

  void push( const ArrayType datum ) {

    if ( dataLength >= size ) {
      setSize( ( size / DYNAMIC_ARRAY_INCREMENT + 1 ) * DYNAMIC_ARRAY_INCREMENT );
    }

    data[ dataLength ] = datum;
    ++dataLength;
  }

  ArrayType& operator[]( size_t index ) {
    return data[ index ];
  }

  ~DynamicArray() {
    delete[] data;
  }
};

#endif

