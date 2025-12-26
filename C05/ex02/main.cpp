#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat  bob("Bob", 1);
    Bureaucrat  alice("Alice", 150);

    ShrubberyCreationForm shrubbery("Home");
    RobotomyRequestForm    robotomy("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << shrubbery;
    std::cout << robotomy;
    std::cout << pardon;

    alice.signForm(shrubbery);
    bob.signForm(shrubbery);
    bob.executeForm(shrubbery);

    alice.signForm(robotomy);
    bob.signForm(robotomy);
    bob.executeForm(robotomy);

    alice.signForm(pardon);
    bob.signForm(pardon);
    bob.executeForm(pardon);

    return 0;
}