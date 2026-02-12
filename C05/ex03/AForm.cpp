#include "AForm.hpp"

AForm::AForm() : name("default"), status(false), sign_grade(150), exec_grade(150)
{
    //std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(std::string const& name, int signgrade, int execgrade) 
: name(name), status(false), sign_grade(signgrade), exec_grade(execgrade)
{
    //std::cout << "AForm parameterized constructor called." << std::endl;
    if (this->sign_grade < 1 || this->exec_grade < 1)
        throw AForm::GradeTooHighException();
    else if (this->sign_grade > 150 || this->exec_grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm&other) 
: name(other.name), status(other.status), sign_grade(other.sign_grade), exec_grade(other.exec_grade)
{
    //std::cout << "AForm copy constructor called." << std::endl;
}

AForm& AForm::operator=(const AForm&other)
{
    //std::cout << "AForm copy assignment operator called." << std::endl;
    if (this != &other)
    {
        this->status = other.status;
    }
    return *this;
}

AForm::~AForm()
{
    //std::cout << "AForm destructor called." << std::endl;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getStatus() const
{
    return status;
}

int AForm::getSignGrade() const
{
    return sign_grade;
}

int AForm::getExecGrade() const
{
    return exec_grade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!!!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!!!";
}

const char* AForm::ExecutionChecksException::what() const throw()
{
    return "Form is not signed or Grade is not high enough!!!";
}

void AForm::beSigned(Bureaucrat &Bureaucrat)
{
    if (Bureaucrat.getGrade() > this->sign_grade)
        throw(AForm::GradeTooLowException());
    else if (this->status == false)
    {
        this->status = true;
    }
}

void AForm::execute(Bureaucrat const & executor) const
{   
    (void)executor; // thiss optional
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm)
{
    out << AForm.getName() << ", AForm status " << AForm.getStatus() << ", signing grade " 
        << AForm.getSignGrade() << " and execution grade " << AForm.getExecGrade() << " ." << std::endl;
    return out;
}
