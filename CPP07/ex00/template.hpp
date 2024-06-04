#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>

void swap( T& a, T& b)
{
  T tmp = a;

  a = b;
  b = tmp;
}

template <typename T>

T& min(T& a, T& b)
{
    return (a > b ? b : a);
}

template <typename T>

T& max(T& a, T& b)
{
    return (a > b ? a : b);
}
#endif
