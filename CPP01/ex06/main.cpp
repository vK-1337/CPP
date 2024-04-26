#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac < 2 || ac > 2)
    {
        std::cout << "Wrong number of arguments." << std::endl;
        std::cout << "Usage: ./HarlFiler <level>" << std::endl;
        std::cout << "4 Differents levels : DEBUG, INFO, WARNING, ERROR" << std::endl;
        return (1);
    }
    else
    {
        Harl harl;
        std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
        std::string level = av[1];
        int i = 0;
        while (i < 4 && level.compare(levels[i]))
            i++;
        switch (i)
        {
        case (0):
            harl.complain("DEBUG");
        case (1):
            harl.complain("INFO");
        case (2):
            harl.complain("WARNING");
        case (3):
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
        }
    }
}