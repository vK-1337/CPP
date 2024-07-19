#include "BitcoinExchange.hpp"

std::multimap<std::string , std::string> fillMapWithCsv(void)
{
  	std::fstream	csv_file;
    std::multimap<std::string , std::string> csv_map;

    csv_file.open("data.csv", std::ios::in);
	  if (!csv_file)
      throw MyException("File not found\n");
    std::string buffer;
    std::getline(csv_file, buffer);

    while (std::getline(csv_file, buffer))
    {
      std::string key = std::strtok(const_cast<char *>(buffer.c_str()), ",");
      std::string value_str = std::strtok(NULL, ",");
      if (!key.empty() && !value_str.empty())
        csv_map.insert(std::make_pair(key, value_str));
    }
    return (csv_map);
}

std::multimap<std::string, std::string> fillMapWithInput(char *map_path)
{
  std::fstream input_file;
  std::multimap<std::string, std::string> input;
  int line_number;

  input_file.open(map_path, std::ios::in);
  if (!input_file)
    throw MyException("Cannot open the input file\n");

  std::string buffer;
  std::getline(input_file, buffer);

  line_number = 1;
  if (!verify_first_line_input(buffer))
  {
    std::ostringstream str_number;
    str_number << line_number;
    std::string error = "Input is not formatted correctly at line " + str_number.str();
    throw MyException(error.c_str());
  }
  while (std::getline(input_file, buffer))
  {
    line_number++;
    std::string error = check_input(buffer);
    std::string key = std::strtok(const_cast<char *>(buffer.c_str()), "|");
    char *value = std::strtok(NULL, "|");
    if (error == "0")
      input.insert(std::make_pair(key, value));
    else
      input.insert(std::make_pair(key, "error " + error));
  }
  return (input);
}

int verify_first_line_input(std::string buffer)
{
  if (buffer != "date | value")
    return (0);
  return (1);
}

std::string check_input(std::string buffer)
{
  std::string checker;
  std::ostringstream converter;
  e_errors error = OK;

  if (buffer.find("-") == std::string::npos || buffer.find("|") == std::string::npos)
    error = BAD_FORMAT;
  else if (bad_date(std::strtok(const_cast<char *>(buffer.c_str()), "|")))
    error = BAD_DATE;
  if (!error)
  {
    std::string value = std::strtok(NULL, "|");
    if (value.find('.') != std::string::npos)
    {
      int occ = std::count(value.begin(), value.end(), '.');
      float number = std::atof(value.c_str());
      if (occ > 1)
        error = BAD_FORMAT;
      else if (number < 0)
        error = NEG_NUMBER;
      else if (number > 1000 || value.size() > 18)
        error = OVERFLOW;
    }
    else
    {
      long number = std::atol(value.c_str());
      if (number < 0)
        error = NEG_NUMBER;
      else if (number > 1000 || value.size() > 4)
        error = OVERFLOW;
    }
  }
  converter << error;
  checker = "" + converter.str();
  return (checker);
}

int bad_date(std::string date)
{
    int year, month, day;
    char dash1, dash2;
    std::istringstream iss(date);

    if (date.size() != 11 && date.at(10) != ' ')
      return (1);
    if (iss >> year >> dash1 >> month >> dash2 >> day)
    {
        if (dash1 == '-' && dash2 == '-' && year >= 1000 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
            if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
              return (1);
            if (month == 2)
            {
                bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                if (day > 29 || (day == 29 && !isLeap))
                  return (1);
            }
            return (0);
        }
    }
    return (1);
}

void print_all_costs(std::multimap<std::string, std::string> input, std::multimap<std::string, std::string> csv_map)
{
  for (std::map<std::string, std::string>::iterator it = input.begin(); it != input.end(); ++it) {

    if (it->second.find("error") != std::string::npos)
    {
      if (it->second.find("1") != std::string::npos)
        std::cout << "Error: bad input => " << it->first << std::endl;
      else if (it->second.find("2") != std::string::npos)
        std::cout << "Error: bad date => " << it->first << std::endl;
      else if (it->second.find("3") != std::string::npos)
        std::cout << "Error: not a positive number." << std::endl;
      else if (it->second.find("4") != std::string::npos)
        std::cout << "Error: too large number." << std::endl;
    }
    else
    {
      std::multimap<std::string, std::string>::iterator lower_date = csv_map.lower_bound(it->first);
      if (lower_date != csv_map.begin() && lower_date->first != it->first)
        lower_date--;
      std::cout << it->first << "=>" << it->second << " = " << atof(it->second.c_str()) * atof(lower_date->second.c_str()) << std::endl;
    }
  }
}
