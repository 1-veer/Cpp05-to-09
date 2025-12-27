#pragma once 

#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);

    private:
        AForm* new_scf(std::string const &target);
        AForm* new_rrf(std::string const &target);
        AForm* new_ppf(std::string const &target);
};

