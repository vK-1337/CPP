#include "rpn.hpp"

int	main(int ac, char **av)
{
	std::string token;
	std::string input;
  std::stack<int> stack;

	for (int i = 1; i < ac; i++)
	{
		if (i > 1)
			input += " ";
		input += av[i];
	}

	std::istringstream tokens(input);

	while (tokens >> token)
	{
    if (std::isdigit(token[0]))
    {
      try
      {
      stack.push(stringToInt(token));
      }
      catch (const std::invalid_argument &e)
      {
        std::cout << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
      }
    }
    else
    {
      if (stack.size() < 2 || token[0] == '(' || token [0] == ')')
      {
        std::cout << "Invalid RPN expression." << std::endl;
        return (1);
      }
      else
      {
        int b = stack.top();
        stack.pop();
        int a = stack.top();
        stack.pop();
        if (token[0] == '+')
          stack.push(a + b);
        else if (token[0] == '-')
          stack.push(a - b);
        else if (token[0] == '*')
          stack.push(a * b);
        else if (token[0] == '/')
          stack.push(a / b);
      }
    }
  }
  if (stack.size() != 1)
  {
    std::cout << "Invalid RPN expression." << std::endl;
    return (EXIT_FAILURE);
  }
  std::cout << stack.top() << std::endl;
  return (EXIT_SUCCESS);
}
