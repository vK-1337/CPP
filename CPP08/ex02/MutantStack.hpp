#include <algorithm>
#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
  public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack &rhs) : std::stack<T, container>(rhs) {};

  iterator begin()
  {
    return this->c.begin();
  }

  iterator end()
  {
    return this->c.end();
  }

  iterator cbegin() const
  {
    return this->c.cbegin();
  }

  iterator cend() const
  {
    return this->c.cend();
  }
};
