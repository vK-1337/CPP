#include "AForm.hpp"

AForm::AForm(std::string name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooLowException();
    if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooHighException();
    std::cout << "A Form has been Created" << std::endl ;
    return;
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
    {
       this->_signed = rhs.isSigned();
    }
    std::cout << "A Bureaucrat name " << this->_name << " has been copied with copy assignement operator." << std::endl;
    return *this;
}

AForm::AForm( const AForm& src ) : _name( src.getName() ), _signGrade( src.getSignGrade() ), _executeGrade( src.getExecuteGrade() ) {}

const std::string AForm::getName() const
{
    return this->_name;
}

unsigned int AForm::getSignGrade() const
{
    return this->_signGrade;
}

unsigned int AForm::getExecuteGrade() const
{
    return this->_executeGrade;
}

bool AForm::isSigned() const
{
    return this->_signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= this->getSignGrade())
        throw AForm::GradeTooLowException();
    this->_signed = true;
    return;
}

std::ostream&   operator<<(std::ostream& stream, const AForm& rhs)
{
    stream << "Form name: " << rhs.getName() << "." << std::endl;
    stream << "Required grade to sign: " << rhs.getSignGrade() << "." << std::endl;
    stream << "Required grade to execute: " << rhs.getExecuteGrade() << "." << std::endl;
    return stream;
}
