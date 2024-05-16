#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern &operator=(const Intern &rhs);
        Intern(const Intern &rhs);
        AForm *makeForm(std::string name, std::string target);
        AForm *PresidentialForm(std::string name);
        AForm *RobotomyForm(std::string name);
        AForm *ShrubberyForm(std::string name);
};
#endif