#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
        void setGrade(int grade);

     public:
        Bureaucrat();
        Bureaucrat(std::string const& name, int grade); 

        Bureaucrat(const Bureaucrat&other);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void incrementGrade(); 
        void decrementGrade(); 

        void signForm(AForm &AForm);
        void executeForm(AForm const & form) const;

        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
       
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

