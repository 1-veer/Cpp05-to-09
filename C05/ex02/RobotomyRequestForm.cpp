#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
: AForm("RobotomyRequestForm", 72, 45),  target("default")
{
    //std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const& target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{
    //std::cout << "RobotomyRequestForm parameterized constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&other) 
: AForm(other), target(other.target)
{
    //std::cout << "RobotomyRequestForm  copy constructor called." << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm&other)
{
    //std::cout << "RobotomyRequestForm copy assignment operator called." << std::endl;
    if (this != &other)
    {
       return *this;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    //std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{   
    if (this->getStatus() == false || executor.getGrade() > this->getExecGrade())
        throw(AForm::ExecutionChecksException());

    std::cout << "* Drilling noises *" << std::endl;
    srand(time(0));
    if (rand() % 2) 
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy on " << target << " has failed." << std::endl;
    /*
    X1 = (a*X0 + c) % m , X0 = time(0) = the seed
    X2 = (a*X1 + c) % m
    X3 = (a*X2 + c) % m ...
    */
}


std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& rrf)
{
    out << rrf.getName() << ", RobotomyRequestForm status " << rrf.getStatus() << ", signing grade " 
        << rrf.getSignGrade() << " and execution grade " << rrf.getExecGrade() << " ." << std::endl;
    return out;
}
