#pragma once

#include <iostream>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;
        void setGrade(int grade);

     public:
        Bureaucrat();
        Bureaucrat(std::string const& name, int grade); 
        ~Bureaucrat();

        Bureaucrat(const Bureaucrat&other);
        Bureaucrat& operator=(const Bureaucrat &other);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade(); 
        void decrementGrade(); 

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

