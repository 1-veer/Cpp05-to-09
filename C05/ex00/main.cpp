#include "Bureaucrat.hpp"

int main ()
{
    try 
    {
        Bureaucrat b1("Ayoub", 50);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Dani", 0); 
        std::cout << b2 << std::endl; // won't get reached , and the control jumps immediately to the nearest handler (catch)
    } 
    catch (Bureaucrat::GradeTooHighException &e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } 
    catch (Bureaucrat::GradeTooLowException &e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    Bureaucrat b3("Veer", 150);
    std::cout << b3 << std::endl;

    try 
    {
        std::cout << "Decrementing Veer's grade..." << std::endl;
        b3.decrementGrade(); 
        std::cout << b3 << std::endl;

        std::cout << "Incrementing Veer's grade..." << std::endl;
        b3.incrementGrade(); 
        std::cout << b3 << std::endl;
    }
     catch (Bureaucrat::GradeTooHighException &e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } 
    catch (Bureaucrat::GradeTooLowException &e) 
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
