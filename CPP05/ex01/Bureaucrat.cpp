#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::~Bureaucrat()
{
    std::cout << "A Bureaucrat has been destroyed" << std::endl ;
    return;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
    if ( grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "A Bureaucrat has been Created" << std::endl ;
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
    *this = rhs;
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    return;
}

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << *this << "signed" << form.getName() << std::endl;
    } catch (Form::GradeTooHighException &e) {
        std::cout << *this << "couldn't sign" << form.getName() << "because" << e.what() << std::endl;
    }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
    if (this != &rhs)
    {
        this->_grade = rhs.getGrade();
    }
    std::cout << "A Bureaucrat named " << rhs.getName() << " has been copied with copy assignement operator." << std::endl;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}
unsigned int Bureaucrat::getGrade() const
{
    return this->_grade;
}
void Bureaucrat::upgrade()
{
    if (this->_grade - 1  < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::downgrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

std::ostream& operator<<( std::ostream& stream, const Bureaucrat& rhs ) {
    stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return stream;
}
