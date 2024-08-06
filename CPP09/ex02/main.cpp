#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Not enough arguments to start computations." << std::endl;
		std::cerr << "Usage exemple: ./PmergeMe 8 9 7 4 5 6" << std::endl;
	}
	try
	{
		verify_input(ac, av);
    sort_with_vect(ac, av);
    sort_with_list(ac, av);
 	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
