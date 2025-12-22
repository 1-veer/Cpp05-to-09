#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat a("ayoub", 5);
    Bureaucrat v("veer", 1);

	Form form1("form1", 4, 4);
	std::cout << form1;

	a.signForm(form1); // he can't
	std::cout << form1; // status still 0

    v.signForm(form1); // he can
    std::cout << form1; // status is now 1

    std::cout << "     ///////////////" <<std::endl;

    Bureaucrat x("X", 2);
    x.signForm(form1);
    std::cout << form1;
	return (0);
}
