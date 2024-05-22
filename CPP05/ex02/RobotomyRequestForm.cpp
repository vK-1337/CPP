#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs), _target(rhs._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    (void)rhs;
    return *this;
}

void RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();

    srand(time(0));

    int randomNumber = rand() % 101;
    if (randomNumber % 2)
        std::cout << _target << " has been successfully robotomized" << std::endl;
    else
        std::cout << _target << " robotomy has failed." << std::endl;
    return;
}