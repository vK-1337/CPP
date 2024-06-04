#ifndef ITER_HPP
#define ITER_HPP

template <typename T>

void iter(T *array, unsigned int len, void *(foo)(T& ))
{
  for (unsigned int i = 0; i < len; i++)
    foo(array[i]);
}
#endif
