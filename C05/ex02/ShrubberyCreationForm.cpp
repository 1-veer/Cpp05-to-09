#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
: AForm("ShrubberyCreationForm", 145, 137),  target("default")
{
    //std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    //std::cout << "ShrubberyCreationForm parameterized constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&other) 
: AForm(other), target(other.target)
{
    //std::cout << "ShrubberyCreationForm  copy constructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&other)
{
    //std::cout << "ShrubberyCreationForm copy assignment operator called." << std::endl;
    if (this != &other)
    {
       AForm::operator=(other);
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    //std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{   
    if (this->getStatus() == false || executor.getGrade() > this->getExecGrade())
        throw(AForm::ExecutionChecksException());

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }
    outfile << "       _-_" << std::endl;
    outfile << "    {~~   ~~}" << std::endl;
    outfile << " /~~    ~    ~~\\" << std::endl;
    outfile << "{     ~   ~     }" << std::endl;
    outfile << "{    \\\\/ \\\\/    }" << std::endl;
    outfile << " \\__  \\\\ //  __/" << std::endl;
    outfile << "~    ~ | | ~`  " << std::endl;
    outfile << "    ~` | |  ~    ~" << std::endl;
    outfile << "  ~    |_|" << std::flush;

    outfile.close();
    std::cout << "Shrubbery has been created in " << target + "_shrubbery" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& scf)
{
    out << scf.getName() << ", ShrubberyCreationForm status " << scf.getStatus() << ", signing grade " 
        << scf.getSignGrade() << " and execution grade " << scf.getExecGrade() << " ." << std::endl;
    return out;
}
