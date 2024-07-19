#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
  if (ac < 2)
  {
    std::cout << "Wrong number of arguments" << std::endl;
    std::cout << "Usage : ./btc input_file_path" << std::endl;
    return (EXIT_FAILURE);
  }

  try
  {
    std::multimap<std::string, std::string> csv_map = fillMapWithCsv();
    try
    {
      std::multimap<std::string , std::string> input_map = fillMapWithInput(av[1]);
      print_all_costs(input_map, csv_map);
    }
    catch (const std::exception &e)
    {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
  catch(const std::exception& e)
  {
    std::cout << "Erreur :" << e.what() << std::endl;
    std::cout << "CSV has not been mapped correctly" << std::endl;
    return (EXIT_FAILURE);
  }
  return (0);
}
// !OK Commencer par stocker le fichier CSV dans une map.

// ? Ensuite verifier l'integrite du fichier input.txt

// ? Stocker input.txt dans un .map

// ? Ensuite iterer a travers ce .map afin de print un par un les equivalents en prix

// ?