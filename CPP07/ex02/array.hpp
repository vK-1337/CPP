#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
  private:
    T *_array;
    unsigned int size;

  public:

  Array(void) : _array(NULL), size(0) {}
  
  Array(unsigned int n) : _array(new T[n]), size(n) {
    for (unsigned int i = 0; i < size; i++)
      _array[i] = T();
  }

  Array(const Array &rhs) : _array(new T[rhs.size]), size(rhs.size)
  {
    for (unsigned int i = 0; i < size; i++)
      _array[i] = rhs._array[i];
  }

  Array &operator=(const Array& rhs)
  {
    if (this != &rhs)
    {
      delete[] _array;
      _array = new T[rhs.size];
      size = rhs.size;
      for (unsigned int i = 0; i < size; i++)
        _array[i] = rhs._array[i];
    }
    return *this;
  }

  ~Array(void)
  {
    delete[] _array;
  }

  unsigned int get_size(void) const
  {
    if (this->_array == NULL)
      return 0;
    return this->size;
  }

  T &operator[](unsigned int i)
  {
    if (i >= size)
      throw OutOfLimitsException();
    return _array[i];
  }

  class OutOfLimitsException : public std::exception
  {
  public:
    virtual const char* what() const throw()
    {
      return "Out of limits";
    }
  };
};


#endif
