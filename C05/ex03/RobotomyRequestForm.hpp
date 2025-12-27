#pragma once 

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string const target;

     public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const& target);

        RobotomyRequestForm(const RobotomyRequestForm&other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm(); 

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& rrf);
