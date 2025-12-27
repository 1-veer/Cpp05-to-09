#include "Form.hpp"

Form::Form() : name("default"), status(false), sign_grade(150), exec_grade(150)
{
    //std::cout << "Form default constructor called." << std::endl;
}

Form::Form(std::string const& name, int signgrade, int execgrade) 
: name(name), status(false), sign_grade(signgrade), exec_grade(execgrade)
{
    //std::cout << "Form parameterized constructor called." << std::endl;
    if (this->sign_grade < 1 || this->exec_grade < 1)
        throw Form::GradeTooHighException();
    else if (this->sign_grade > 150 || this->exec_grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form&other) 
: name(other.name), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
    //std::cout << "Form  copy constructor called." << std::endl;
    *this = other;
}

Form& Form::operator=(const Form&other)
{
    //std::cout << "Form copy assignment operator called." << std::endl;
    if (this != &other)
    {
        this->status = other.status;
    }
    return *this;
}
Form::~Form()
{
    //std::cout << "Form destructor called." << std::endl;
}

std::string Form::getName() const
{
    return name;
}

bool Form::getStatus() const
{
    return status;
}

int Form::getSignGrade() const
{
    return sign_grade;
}

int Form::getExecGrade() const
{
    return exec_grade;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!!!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!!!";
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() > this->sign_grade)
        throw(Form::GradeTooLowException());
    else if (this->status == false)
    {
        this->status = true;
    }
}

std::ostream& operator<<(std::ostream& out, const Form& Form)
{
    out << Form.getName() << ", Form status " << Form.getStatus() << ", signing grade " 
        << Form.getSignGrade() << " and execution grade " << Form.getExecGrade() << " ." << std::endl;
    return out;
}
