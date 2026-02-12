#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* scf;
    AForm* ppf; 

    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    scf = someRandomIntern.makeForm("ShrubberyCreationForm", "Home");
    ppf = someRandomIntern.makeForm("PresidentialPardonForm", "Arthur Dent");
    AForm* unknown = someRandomIntern.makeForm("UnknownForm", "Nobody");    
    Bureaucrat boss("Boss", 1);
    if (scf)
    {
        boss.signForm(*scf);
        boss.executeForm(*scf);
    }

    delete rrf;
    delete scf;
    delete ppf;
    if (unknown)
        delete unknown;
    
    return 0;
}