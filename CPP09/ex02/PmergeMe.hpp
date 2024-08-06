#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <algorithm>
# include <cstring>
# include <iostream>
# include <list>
# include <sstream>
# include <string>
# include <vector>
#include <iterator>
#include <ctime>

class MyException : public std::exception
{
  private:
	char *msg;

  public:
	MyException(const char *message)
	{
		msg = new char[std::strlen(message) + 1];
		std::strcpy(msg, message);
	}

	virtual const char *what() const throw()
	{
		return (msg);
	}

	virtual ~MyException() throw()
	{
		delete[] msg;
	}
};

void	verify_input(int ac, char **av);
void	isInteger(const std::string &str);
void	isNeg(const std::string &str);
void	alreadySorted(std::string input);
void	sort_with_vect(int ac, char **av);
void	divide_and_conquer_vect(std::vector<int> numbers,
			std::vector<int> *mins, std::vector<int> *maxs);
std::vector<int> merge_sort_vect(std::vector<int> maxs, std::vector<int> mins);
void	push_element_vect(std::vector<int> *maxs, std::vector<int> *mins,
			size_t index);
std::vector<int> recursive_sort_vect(std::vector<int> numbers);
void	print_vect(std::vector<int> numbers);
void sort_with_list(int ac, char **av);
std::list<int>recursive_sort_list(std::list<int> numbers);
void divide_and_conquer_list(const std::list<int>& numbers, std::list<int>* mins, std::list<int>* maxs);
void push_element_list(std::list<int>* mins, std::list<int>* maxs, size_t index);
std::list<int> merge_sort_list(std::list<int> maxs, std::list<int> mins);
void print_list(std::list<int> numbers);
#endif
