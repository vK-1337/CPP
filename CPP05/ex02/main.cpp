#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
    try {
      AForm form("Contrat", 0, 50);
    } catch (std::exception &e) {
      std::cout << "Couldn't create the first form because: " << e.what() << std::endl;
    }

    try {
      AForm form("Contrat", 1, 0);
    } catch (std::exception &e) {
      std::cout << "Couldn't create the second form because: " << e.what() << std::endl;
    }

    try {
      AForm form("Contrat", 10, 10);
      Bureaucrat donDrapper("Don", 20);
      donDrapper.signForm(form);
    } catch (std::exception &e) {
      std::cout << "Can't sign the form because: " << e.what() << std::endl;
    }

    try {
      AForm form("Contrat", 10, 10);
      Bureaucrat donDrapper("Don", 8);
      donDrapper.signForm(form);
    } catch (std::exception &e) {
      std::cout << "Can't sign the form because: " << e.what() << std::endl;
    }

    return 0;
}
