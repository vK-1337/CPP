#include "BitcoinExchange.hpp"

int main(void)
{
  std::multimap<std::string, std::string> input;

  std::string input_path = "input.txt";
  input = fillMapWithInput(const_cast<char *>(input_path.c_str()));

  for (std::map<std::string, std::string>::iterator it = input.begin(); it != input.end(); ++it) {
    std::cout << it->first << " : " << it->second << std::endl;
  }
  return (0);
}
