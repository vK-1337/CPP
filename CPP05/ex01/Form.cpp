#include "Form.hpp"

Form::Form(std::string name, unsigned int signGrade, unsigned int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooLowException();
    if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooHighException();
    std::cout << "A Form has been Created" << std::endl ;
    return;
}

Form::~Form() {}

Form &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
    {
       this->_signed = rhs.isSigned();
    }
    std::cout << "A Bureaucrat name " << this->_name << " has been copied with copy assignement operator." << std::endl;
    return *this;
}

Form::Form( const Form& src ) : _name( src.getName() ), _signGrade( src.getSignGrade() ), _executeGrade( src.getExecuteGrade() ) {}

const std::string Form::getName() const
{
    return this->_name;
}

unsigned int Form::getSignGrade() const
{
    return this->_signGrade;
}

unsigned int Form::getExecuteGrade() const
{
    return this->_executeGrade;
}

bool Form::isSigned() const
{
    return this->_signed;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() >= this->getSignGrade())
        throw Form::GradeTooLowException();
    this->_signed = true;
    return;
}

std::ostream&   operator<<(std::ostream& stream, const Form& rhs)
{
    stream << "Form name: " << rhs.getName() << "." << std::endl;
    stream << "Required grade to sign: " << rhs.getSignGrade() << "." << std::endl;
    stream << "Required grade to execute: " << rhs.getExecuteGrade() << "." << std::endl;
    return stream;
}
