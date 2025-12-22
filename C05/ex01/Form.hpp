#pragma once 

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const name;
        bool status;
        int const sign_grade;
        int const exec_grade;

     public:
        Form();
        Form(std::string const& name, int signgrade, int execgrade);

        Form(const Form&other);
        Form& operator=(const Form &other);
        ~Form();

        std::string getName() const;
        bool getStatus() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat &Bureaucrat);

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

std::ostream& operator<<(std::ostream& out, const Form& Form);
