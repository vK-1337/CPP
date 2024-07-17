#include <vector>
#include <iostream>
#include <algorithm>

#include "span.hpp"

int main(int ac, char **av)
{

  (void)ac, (void)av;

  Span<int> sp(5);

  sp.addNumber(6);

  sp.addNumber(3);

  sp.addNumber(17);

  sp.addNumber(9);

  sp.addNumber(11);

  std::cout << sp.shortestSpan() << std::endl;

  std::cout << sp.longestSpan() << std::endl;

  
  return (0);
}
