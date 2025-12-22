#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    //std::cout << "Bureaucrat default constructor called." << std::endl;
}
Bureaucrat::Bureaucrat(std::string const& name, int grade) : name(name)
{
    //std::cout << "Bureaucrat parameterized constructor called." << std::endl;
    this->setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat&other) : name(other.name)
{
    //std::cout << "Bureaucratzzz copy constructor called." << std::endl;
    *this = other;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat&other)
{
    //std::cout << "Bureaucrat copy assignment operator called." << std::endl;
    if (this != &other)
    {
        this->setGrade(other.grade);
    }
    return *this;
}
Bureaucrat::~Bureaucrat()
{
    //std::cout << "Bureaucrat destructor called." << std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}
int Bureaucrat::getGrade() const
{
    return this->grade;
}
void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    this->setGrade(this->grade -1);
}

void Bureaucrat::decrementGrade()
{
    this->setGrade(this->grade +1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!!!";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}
