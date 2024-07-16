#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

template <typename T>
class Array
{
  private:
    T *array;
    unsigned int size;

  public:

  Array(void) : array(NULL), size(0) {}
  Array(unsigned int n) : array(new T[n]), size(n) {}
  Array(const Array &rhs) : array(new T[rhs.size]), size(rhs.size)
  {
    for (unsigned int i = 0; i < size; i++)
      array[i] = rhs.array[i];
  }
  Array &operator=(const Array& rhs)
  {
    if (this != &rhs)
    {
      delete[] array;
      array = new T[rhs.size];
      size = rhs.size;
      for (unsigned int i = 0; i < size; i++)
        array[i] = rhs.array[i];
    }
    return *this;
  }

  ~Array(void)
  {
    delete[] array;
  }

  unsigned int get_size(void) const
  {
    if (this->array == NULL)
      return 0;
    return this->size;
  }

  T &operator[](unsigned int i)
  {
    if (i >= size)
      throw OutOfLimitsException();
    return array[i];
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
