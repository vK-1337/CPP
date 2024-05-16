#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string &target);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
        PresidentialPardonForm(const PresidentialPardonForm &rhs);

        void        execute( const Bureaucrat& executor );
};
#endif
