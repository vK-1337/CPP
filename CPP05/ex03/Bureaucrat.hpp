#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
        Bureaucrat();

    public:
        ~Bureaucrat();
        Bureaucrat(std::string name, unsigned int grade);
        Bureaucrat(const Bureaucrat &rhs);
        Bureaucrat &operator=(const Bureaucrat& rhs);
        std::string getName() const;
        unsigned int getGrade() const;
        void upgrade(); // Remember that upgrade means grade--;
        void downgrade(); // Remember that downgrade means grade++;
        void signForm(AForm &form);
        void executeForm(AForm const & form);
        
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

std::ostream&   operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif
