#pragma once 

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string const target;

     public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const& target);

        ShrubberyCreationForm(const ShrubberyCreationForm&other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm(); // implicitly virtual 

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& scf);
