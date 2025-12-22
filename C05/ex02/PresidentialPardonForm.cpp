#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
: AForm("PresidentialPardonForm", 25, 5),  target("default")
{
    //std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{
    //std::cout << "PresidentialPardonForm parameterized constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm&other) 
: AForm(other), target(other.target)
{
    //std::cout << "PresidentialPardonFormzzz copy constructor called." << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&other)
{
    //std::cout << "PresidentialPardonForm copy assignment operator called." << std::endl;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    //std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{   
    if (this->getStatus() == false || executor.getGrade() > this->getExecGrade())
        throw(AForm::ExecutionChecksException());
    
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& PresidentialPardonForm)
{
    out << PresidentialPardonForm.getName() << ", PresidentialPardonForm status " << PresidentialPardonForm.getStatus() << ", signing grade " 
        << PresidentialPardonForm.getSignGrade() << " and execution grade " << PresidentialPardonForm.getExecGrade() << " ." << std::endl;
    return out;
}
