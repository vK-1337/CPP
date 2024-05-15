#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat testTooLow("Toolow", 0);
    } catch ( const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat testTooHigh("Toohigh", 151);
    } catch ( const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat donDrapper("Don", 1);
        std::cout << donDrapper << std::endl;
        donDrapper.upgrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
