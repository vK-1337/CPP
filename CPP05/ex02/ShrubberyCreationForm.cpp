#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm(rhs), _target(rhs._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    (void) rhs;
    return *this;;
}

void        ShrubberyCreationForm::execute( const Bureaucrat& executor )
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::fstream new_file;
    new_file.open(this->_target.append("_shrubbery"), std::ios::out);
    if (!new_file)
    {
        std::cout << "File couldn't be created" << std::endl;
        return;
    }
    new_file << "ASCII trees";
    new_file.close();
    return;
}
