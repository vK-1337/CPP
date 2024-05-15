#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const unsigned int _signGrade;
        const unsigned int _executeGrade;
        Form();
    public:
        Form(std::string name, unsigned int signGrade, unsigned int executeGrade);
        ~Form();
        Form &operator=(const Form &rhs);
        Form(const Form &rhs);
        const std::string getName() const;
        unsigned int getSignGrade() const;
        unsigned int getExecuteGrade() const;
        bool isSigned() const;
        void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return "Grade is too high!";
            }
        };

    class GradeTooLowException : public std::exception
        {
        public:
            virtual const char* what() const throw()
            {
                return "Grade is too low!";
            }
        };
};

std::ostream&   operator<<(std::ostream& o, const Form& rhs);

#endif
