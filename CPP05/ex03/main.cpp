#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main(void)
{
	AForm *a;
	AForm *b;
	AForm *c;

	std::cout << std::endl;

	Intern Arnaldo;
    std::cout << std::endl;

	a = Arnaldo.makeForm("robotomy request form", "Ebil");
	std::cout << std::endl;
	b = Arnaldo.makeForm("presidential pardon form", "Ebil");
	std::cout << std::endl;
	c = Arnaldo.makeForm("shrubbery creation form", "Ebil");
	std::cout << std::endl;

	Arnaldo.makeForm("foo", "Ebil");
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	return EXIT_SUCCESS;
}