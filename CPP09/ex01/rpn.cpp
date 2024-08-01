#include "rpn.hpp"

int stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int value;
    iss >> value;
    if (iss.fail())
        throw std::invalid_argument("Conversion en entier échouée : " + str);
    if (str.find('.') != std::string::npos)
        throw std::invalid_argument("L'element suivant est un float : " + str);
    return value;
}
