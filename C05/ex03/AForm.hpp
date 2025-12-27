#pragma once 

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const name;
        bool status;
        int const sign_grade;
        int const exec_grade;

     public:
        AForm();
        AForm(std::string const& name, int signgrade, int execgrade);

        AForm(const AForm&other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getStatus() const;
        int getSignGrade() const;
        int getExecGrade() const;

        void beSigned(Bureaucrat &Bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;

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

        class ExecutionChecksException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
       
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);
