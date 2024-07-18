#include "BitcoinExchange.hpp"

std::multimap<std::string , float> fillMapWithCsv(void)
{
  	std::fstream	csv_file;
    std::multimap<std::string , float> csv_map;

    csv_file.open("data.csv", std::ios::in);
	  if (!csv_file)
      throw MyException("File not found\n");
    std::string buffer;
    std::getline(csv_file, buffer);

    while (std::getline(csv_file, buffer))
    {
      std::string key = std::strtok(const_cast<char *>(buffer.c_str()), ",");
      char *value_str = std::strtok(NULL, ",");
      if (!key.empty() && value_str)
      {
        float value = strtof(value_str, NULL);
        csv_map.insert(std::make_pair(key, value));
      }
    }
    return (csv_map);
}

std::multimap<std::string, float> fillMapWithInput(char *map_path)
{
  std::fstream input_file;
  std::multimap<std::string, float> input;
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
    std::string error = check_input(buffer);
    std::string key = std::strtok(const_cast<char *>(buffer.c_str()), "|");
    char *value = std::strtok(NULL, "|");
    if (error != "OK")
      input.insert(std::make_pair(key, strtof(value, NULL)));
    else
      input.insert
  }
  return (input);
}

int verify_first_line_input(std::string buffer)
{
  if (buffer.find("date | value\n") == std::string::npos)
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
    long atol = std::atol(value.c_str());
    if (atol < 0)
      error = NEG_NUMBER;
    else if (atol > 1000 || value.size() > 10)
      error = OVERFLOW;
  }
  converter << error;
  checker = "" + converter.str();
  std::cout << checker << std::endl;
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
