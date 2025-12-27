#pragma once 

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string const target;

     public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const& target);

        PresidentialPardonForm(const PresidentialPardonForm&other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm(); // implicitly virtual 

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& ppf);
