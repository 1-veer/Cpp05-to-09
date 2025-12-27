#include "Intern.hpp"

Intern::Intern() 
{
    //std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern&other) 
{
    *this = other;
    //std::cout << "Intern copy constructor called." << std::endl;
}

Intern& Intern::operator=(const Intern&other)
{
    //std::cout << "Intern copy assignment operator called." << std::endl;
    if (this != &other)
    {
       return *this;
    }
    return *this;
}
Intern::~Intern()
{
    //std::cout << "Intern destructor called." << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    AForm *res = nullptr;
    std::string forms[] = { "ShrubberyCreationForm" , "RobotomyRequestForm" , "PresidentialPardonForm"};

    AForm* (Intern::*fcts[]) (std::string const &target) = { &Intern::new_scf , &Intern::new_rrf , &Intern::new_ppf};

    for (int i=0; i<3 ; i++)
    {
        if (formName == forms[i])
        {
            res = (this->*fcts[i])(target);
            std::cout << "Intern creates " << formName << std::endl;
            return res;
        }   
    }
    if (res == nullptr)
        std::cout << "Intern couldn't find the form " << formName << std::endl;
    return res;
}


AForm* Intern::new_scf(std::string const &target)
{
    AForm *scf = new ShrubberyCreationForm(target);
    return scf;
}
AForm* Intern::new_rrf(std::string const &target)
{
    AForm *rrf = new RobotomyRequestForm(target);
    return rrf;
}
AForm* Intern::new_ppf(std::string const &target)
{
    AForm *ppf = new PresidentialPardonForm(target);
    return ppf;
}   


