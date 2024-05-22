#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "An Intern has been created." << std::endl;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs)
{
    (void) rhs;
    std::cout << "An Intern has been copied with copy assignement operator." << std::endl;
    return *this;
}

Intern::Intern(const Intern &rhs)
{
    *this = rhs;
    std::cout << "Intern copy constructor called" << std::endl;
    return;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    typedef AForm* (Intern::*FormFunctionPtr)(std::string);
    int i = 0;
    FormFunctionPtr forms[] = { &Intern::PresidentialForm, &Intern::RobotomyForm, &Intern::ShrubberyForm };
    std::string formNames[3] = { "presidential pardon form", "robotomy request form", "shrubbery creation form"};
    while (i < 3 && formNames[i].compare(name))
        i++;
    if (i < 3)
        return (this->*forms[i])(target);
    std::cout << "The form couldn't be created because the name specified don't exist." << std::endl;
    return NULL;
}

AForm *Intern::PresidentialForm(std::string target)
{
    return new PresidentialPardonForm(target);
}
AForm *Intern::RobotomyForm(std::string target)
{
    return new RobotomyRequestForm(target);
}
AForm *Intern::ShrubberyForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}