#include "PmergeMe.hpp"

void sort_with_vect(int ac, char **av)
{
  std::vector<int> numbers;
  std::string input;

  clock_t start_time = clock();
  for (int i = 1; i < ac; i++)
  {
  if (i > 1)
    input += " ";
  input += av[i];
  }

  std::istringstream tokens(input);

  for (int number; tokens >> number;)
    numbers.push_back(number);

  std::vector<int> sorted_numbers;

  sorted_numbers = recursive_sort_vect(numbers);
  clock_t end_time = clock();

  double elapsed_time_us = double(end_time - start_time) / CLOCKS_PER_SEC * 1e6;
  std::cout << "Before:   ";
  print_vect(numbers);
  std::cout << "After:    ";
  print_vect(sorted_numbers);
  std::cout << "Time to process a range of " << numbers.size() << " elements with std::[vector] : " << elapsed_time_us << " us" << std::endl;
}

std::vector<int>recursive_sort_vect(std::vector<int> numbers)
{

  std::vector<int> mins;
  std::vector<int> maxs;

  divide_and_conquer_vect(numbers, &mins, &maxs);
  if (maxs.size() != 1)
  {
    maxs = recursive_sort_vect(maxs);
  }
  return (merge_sort_vect(maxs, mins));
}

std::list<int>recursive_sort_list(std::list<int> numbers)
{

  std::list<int> mins;
  std::list<int> maxs;

  divide_and_conquer_list(numbers, &mins, &maxs);
  if (maxs.size() != 1)
  {
    maxs = recursive_sort_list(maxs);
  }
  return (merge_sort_list(maxs, mins));
}

std::list<int> merge_sort_list(std::list<int> maxs, std::list<int> mins) {

    if (maxs.size() == 1 && mins.empty())
        return maxs;
    const std::size_t JacobsthalSequence[] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531};

    std::size_t pushed = 0;
    std::size_t index = 0;

    push_element_list(&mins, &maxs, index);
    pushed++;
    index++;

    while (pushed < mins.size())
    {
        std::size_t j_number = JacobsthalSequence[index];
        std::size_t j_number_m_1 = JacobsthalSequence[index - 1];
        while (j_number > j_number_m_1 && pushed != mins.size())
        {
            if (j_number <= mins.size())
            {
                push_element_list(&mins, &maxs, j_number - 1);
                pushed++;
            }
            j_number--;
        }
        index++;
    }
    return (maxs);
}

std::vector<int> merge_sort_vect(std::vector<int> maxs, std::vector<int> mins)
{
    if (maxs.size() == 1 && mins.size() == 0)
        return (maxs);

    const std::size_t JacobsthalSequence[] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971,  357913941, 715827883, 1431655765, 2863311531};

    std::size_t pushed = 0;
    std::size_t index = 0;

    push_element_vect(&mins, &maxs, index);
    pushed++;
    index++;

    while (pushed < mins.size())
    {
        std::size_t j_number = JacobsthalSequence[index];
        std::size_t j_number_m_1 = JacobsthalSequence[index - 1];
        while (j_number > j_number_m_1 && pushed != mins.size())
        {
            if (j_number <= mins.size())
            {
                push_element_vect(&mins, &maxs, j_number - 1);
                pushed++;
            }
            j_number--;
        }
        index++;
    }
    return (maxs);
}

void push_element_vect(std::vector<int> *mins, std::vector<int> *maxs, size_t index)
{

    std::vector<int>::iterator pos = std::upper_bound(maxs->begin(), maxs->end(), mins->at(index));
    maxs->insert(pos, mins->at(index));
}


void push_element_list(std::list<int>* mins, std::list<int>* maxs, size_t index)
{
    if (index >= mins->size())
    {
        return;
    }

    std::list<int>::iterator it = mins->begin();
    std::advance(it, index);
    int element_to_insert = *it;

    if (maxs->empty())
    {
        maxs->push_back(element_to_insert);
        return;
    }

    std::list<int>::iterator begin = maxs->begin();
    std::list<int>::iterator end = maxs->end();
    std::list<int>::iterator mid;

    while (std::distance(begin, end) > 1)
    {
        mid = begin;
        std::advance(mid, std::distance(begin, end) / 2);

        if (element_to_insert <= *mid)
        {
            end = mid;
        } else {
            begin = mid;
            std::advance(begin, 1);
        }
    }
    if (element_to_insert > *begin)
    {
        maxs->insert(end, element_to_insert);
        return;
    }
    maxs->insert(begin, element_to_insert);
}

void print_vect(std::vector<int> numbers)
{
  for (size_t i = 0; i < numbers.size(); ++i)
  {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void divide_and_conquer_vect(std::vector<int> numbers, std::vector<int> *mins, std::vector<int> *maxs)
{
  std::vector<int> pairs;
  for (size_t i = 0; i < numbers.size(); i++)
  {
    pairs.push_back(numbers[i]);
    if (pairs.size() == 2)
    {
      if (pairs[0] > pairs[1])
      {
        maxs->push_back(pairs[0]);
        mins->push_back(pairs[1]);
      }
      else
      {
        maxs->push_back(pairs[1]);
        mins->push_back(pairs[0]);
      }
      pairs.clear();
    }
    else if (pairs.size() == 1 && i == (numbers.size() - 1))
    {
      mins->push_back(pairs[0]);
    }
  }
}

void divide_and_conquer_list(const std::list<int>& numbers, std::list<int>* mins, std::list<int>* maxs) {
    if (numbers.empty()) return;

    std::list<int>::const_iterator it = numbers.begin();

    while (it != numbers.end()) {
        std::list<int>::const_iterator next_it = it;
        ++next_it;

        if (next_it != numbers.end()) {
            int first = *it;
            int second = *next_it;

            if (first > second) {
                maxs->push_back(first);
                mins->push_back(second);
            } else {
                maxs->push_back(second);
                mins->push_back(first);
            }

            std::advance(it, 2);
        } else {
            maxs->push_back(*it);
            ++it;
        }
    }
}

void print_list(std::list<int> numbers)
{
  for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void sort_with_list(int ac, char **av)
{
  std::list<int> numbers;
  std::string input;

  clock_t start_time = clock();
  for (int i = 1; i < ac; i++)
  {
  if (i > 1)
    input += " ";
  input += av[i];
  }

  std::istringstream tokens(input);

  for (int number; tokens >> number;)
    numbers.push_back(number);

  std::list<int> sorted_numbers;


  sorted_numbers = recursive_sort_list(numbers);
  clock_t end_time = clock();

  double elapsed_time_us = double(end_time - start_time) / CLOCKS_PER_SEC * 1e6;
  std::cout << "Time to process a range of " << numbers.size() << " elements with std::[list] : " << elapsed_time_us << " us" << std::endl;
}

void alreadySorted(std::string input)
{

  std::istringstream tokens(input);
  std::vector<int> numbers;
  int previous_number = 0;

  for (int number; tokens >> number;)
  {
    numbers.push_back(number);
    if (number < previous_number)
      return;
    previous_number = number;
  }
  throw MyException("List is already sorted!");
}

void isInteger(const std::string& str)
{
    std::istringstream iss(str);
    int value;
    char c;

     if (!(iss >> value) && !(iss >> c))
     {
       throw MyException("One element is not an int.");
     }
}

void isNeg(const std::string &str)
{
    std::istringstream iss(str);
    int value;

    iss >> value;

    if (value < 0)
      throw MyException("One element is negative.");
}

void verify_input(int ac, char **av)
{

  std::string input;
  std::string token;

  for (int i = 1; i < ac; i++)
	{
		if (i > 1)
			input += " ";
		input += av[i];
	}

  std::istringstream tokens(input);

  try
  {
    while (tokens >> token)
    {
      try
      {
        isInteger(token);
        isNeg(token);
      }
      catch (std::exception &e)
      {
        throw MyException(e.what());
      }
    }
    alreadySorted(input);
  }
  catch (std::exception &e)
  {
    throw MyException(e.what());
  }
}
