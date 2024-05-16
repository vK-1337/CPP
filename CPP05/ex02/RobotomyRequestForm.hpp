#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string &target);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
        RobotomyRequestForm(const RobotomyRequestForm &rhs);

        void        execute( const Bureaucrat& executor );
};
#endif
