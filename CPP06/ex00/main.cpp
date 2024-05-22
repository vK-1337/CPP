#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

int main(int ac, char** av) {
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        std::cout << "Usage : ./convert [literal]" << std::endl;
        return 1;
    }
    ScalarConverter converter;
    converter.convert(av[1]);
    return 0;
}
