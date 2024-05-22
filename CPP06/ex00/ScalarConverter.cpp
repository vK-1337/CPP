#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>

void ScalarConverter::convert(std::string literal)
{
    char charConversion;
    int intConversion;
    float floatConversion;
    double doubleConversion;

    std::string pseudoLiterals[6] = {"-inff", "+inff", "-inf", "+inf", "nan", "nanf"};
    bool found = false;
    bool positivePseudoLiteral = false;
    for(const std::string& element : pseudoLiterals) {
        if(literal == element) {
            found = true;
            if (element[0] == '+')
                positivePseudoLiteral = true;
            break;
        }
    }
    if (found)
    {
        doubleConversion = std::atof(literal.c_str());
        floatConversion = static_cast<float>(doubleConversion);
        std::cout << "Char conversion: " << "Impossible" << std::endl;
        std::cout << "Int conversion: " << "Impossible" << std::endl;
        std::cout << "Float conversion: ";
        if (positivePseudoLiteral)
            std::cout << "+";
        std::cout << floatConversion << "f" << std::endl;
        std::cout << "Double conversion: ";
        if (positivePseudoLiteral)
            std::cout << "+";
        std::cout << doubleConversion << std::endl;
        return;
    }
    if (literal.back() == 'f')
    {
        floatConversion = std::atof(literal.c_str());
        intConversion = static_cast<int> (floatConversion);
        charConversion = static_cast<char>(floatConversion);
        doubleConversion = static_cast<double> (floatConversion);
        if (std::isprint(charConversion))
            std::cout << "Char conversion: " << "'" << charConversion << "'" << std::endl;
        else
            std::cout << "Char conversion: " << "Impossible" << std::endl;
        std::cout << "Int conversion: " << intConversion << std::endl;
        if (intConversion == floatConversion)
            std::cout << "Float conversion: " << floatConversion << ".0f" << std::endl;
        else
            std::cout << "Float conversion: " << floatConversion << "f" << std::endl;
        if (intConversion == doubleConversion)
            std::cout << "Double conversion: " << doubleConversion << ".0" << std::endl;
        else
            std::cout << "Double conversion: " << doubleConversion << std::endl;
        return;
    }

    if (literal.find('.') != std::string::npos)
    {
        doubleConversion = std::atof(literal.c_str());
        floatConversion = static_cast<double> (doubleConversion);
        intConversion = static_cast<int> (doubleConversion);
        charConversion = static_cast<char>(doubleConversion);
        if (std::isprint(charConversion))
            std::cout << "Char conversion: " << "'" << charConversion << "'" << std::endl;
        else
            std::cout << "Char conversion: " << "Impossible" << std::endl;
        std::cout << "Int conversion: " << intConversion << std::endl;
        if (intConversion == floatConversion)
            std::cout << "Float conversion: " << floatConversion << ".0f" << std::endl;
        else
            std::cout << "Float conversion: " << floatConversion << "f" << std::endl;
        if (intConversion == doubleConversion)
            std::cout << "Double conversion: " << doubleConversion << ".0" << std::endl;
        else
            std::cout << "Double conversion: " << doubleConversion << std::endl;
        return;
    }

    bool literalIsInt = true;
    bool firstChar = true;

    for (char c : literal) {
        if (firstChar && (c == '-' || c == '+'))
        {
            firstChar = false;
            continue;
        }
        if (!std::isdigit(c)) {
            literalIsInt = false;
        }
    }

    if (literalIsInt)
    {
        intConversion = std::atoi(literal.c_str());
        charConversion = static_cast<char>(intConversion);
        floatConversion = static_cast <float> (intConversion);
        doubleConversion = static_cast<double> (intConversion);
        if (std::isprint(charConversion))
            std::cout << "Char conversion: " << "'" << charConversion << "'" << std::endl;
        else
            std::cout << "Char conversion: " << "Impossible" << std::endl;
        std::cout << "Int conversion: " << intConversion << std::endl;
        std::cout << "Float conversion: " << intConversion << ".0f" << std::endl;
        std::cout << "Double conversion: " << intConversion << ".0" << std::endl;
        return ;
    }

    if (literal.size() == 1 && std::isprint(literal[0])) // Mean its a printable char
    {
        charConversion = literal[0];
        intConversion = static_cast <int> (charConversion);
        floatConversion = static_cast <float> (charConversion);
        doubleConversion = static_cast <double> (charConversion);
        std::cout << "Char conversion: " << "'" << charConversion << "'" << std::endl;
        std::cout << "Int conversion: " << intConversion << std::endl;
        std::cout << "Float conversion: " << floatConversion << ".0f" << std::endl;
        std::cout << "Double conversion: " << doubleConversion << ".0" << std::endl;
        return ;
    }
    std::cout << "Unknown literal, please enter either a char, an int, a float or a double" << std::endl;
    return;
}