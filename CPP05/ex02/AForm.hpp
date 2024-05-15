#ifndef AAFORM_HPP
#define AAFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const unsigned int _signGrade;
        const unsigned int _executeGrade;
        AForm();
    public:
        AForm(std::string name, unsigned int signGrade, unsigned int executeGrade);
        ~AForm();
        AForm &operator=(const AForm &rhs);
        AForm(const AForm &rhs);
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

std::ostream&   operator<<(std::ostream& o, const AForm& rhs);

#endif
