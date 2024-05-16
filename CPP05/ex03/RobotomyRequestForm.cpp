#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("robotomy request form", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs), _target(rhs._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    (void)rhs;
    return *this;
}

void        RobotomyRequestForm::execute( const Bureaucrat& executor ) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();

    std::random_device rd;
    std::mt19937 gen(rd());

    // Définit la plage des nombres aléatoires (0-100)
    std::uniform_int_distribution<> dis(0, 100);

    // Génère un nombre aléatoire
    int randomNumber = dis(gen);
    if (randomNumber % 2)
        std::cout << _target << " has been successfully robotomized" << std::endl;
    else
        std::cout << _target << " robotomy has failed." << std::endl;
    return;
}