#include "array.hpp"

int main(void)
{
  Array<int> a(10);
  Array<int> b(a);
  Array<int> c = b;

  std::cout << "a.get_size() = ";
  std::cout << a.get_size() << std::endl;

  std::cout << "A basic" << std::endl;
  std::cout << std::endl;
  for (unsigned  i = 0; i < a.get_size(); i++)
  {
    std::cout << "a[" << i << "] = ";
    std::cout << a[i] << std::endl;
  }

  std::cout << std::endl;

  for (unsigned int i = 0; i < a.get_size(); i++)
    a[i] = i;

  std::cout << "After setting values" << std::endl;
  std::cout << std::endl;
  for (unsigned  i = 0; i < a.get_size(); i++)
  {
    std::cout << "a[" << i << "] = ";
    std::cout << a[i] << std::endl;
  }

  std::cout << std::endl;
  for (unsigned  i = 0; i < b.get_size(); i++)
  {
    std::cout << "b[" << i << "] = ";
    std::cout << b[i] << std::endl;
  }

  std::cout << std::endl;
  for (unsigned  i = 0; i < c.get_size(); i++)
  {
    std::cout << "c[" << i << "] = ";
    std::cout << c[i] << std::endl;
  }

  std::cout << std::endl;

  try
  {
    std::cout << "Trying to access a[10] and fill it with 42" << std::endl;
    a[10] = 42;
  }
  catch (Array<int>::OutOfLimitsException &e)
  {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
