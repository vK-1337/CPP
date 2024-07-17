#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> class Span
{
  private:
	std::vector<T> vec;
	unsigned int _capacity;
	unsigned int _size;

  public:
	Span(unsigned int N) : vec(N), _capacity(N), _size(0){};

	Span(const Span &rhs) : vec(rhs.vec){};

	~Span(){};

	void addNumber(int number)
	{
		if (_size == _capacity)
		{
			throw std::out_of_range("Span is full");
		}
		vec.at(_size) = number;
		_size++;
	}

	T shortestSpan()
	{
		if (!this->vec.size() || this->vec.size() == 1)
			throw std::logic_error("Not enough element to find a Span");
		std::vector<T> sorted = this->vec;
		std::sort(sorted.begin(), sorted.end());
		return (-(*sorted.begin() - (*(sorted.begin() + 1)) + 1));
	}

	T longestSpan()
	{
		if (!this->vec.size() || this->vec.size() == 1)
			throw std::logic_error("Not enough element to find a Span");
		std::vector<T> sorted = this->vec;
		std::sort(sorted.begin(), sorted.end());
		return (-(*sorted.begin() - (*(sorted.end() - 1))));
	}

	void addRange(T start, T end)
	{
		if (_size == _capacity)
		{
			throw std::out_of_range("Span is full");
		}
		if (start >= end)
		{
			throw std::logic_error("Start should be less than end");
		}
		size_t rangeSize = end - start;
		if (rangeSize > (_capacity - _size))
		{
			throw std::logic_error("Not enough space to store all");
		}
		for (T value = start; value <= end; ++value)
		{
			vec[_size++] = value;
		}
	}

	void printVec()
	{
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
	}
};
