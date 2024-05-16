#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string &target);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
        ShrubberyCreationForm(const ShrubberyCreationForm &rhs);

        void        execute( const Bureaucrat& executor );
};
#endif
