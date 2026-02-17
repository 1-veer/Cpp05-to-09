#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void)
{
    std::srand(std::time(0));
    int i;
    i = std::rand() % 3;
    if (i == 0)
    {
        std::cout << "A was generated" << std::endl;
        return (new A);
    }
    else if (i == 1)
    {
        std::cout << "B was generated" << std::endl;
        return (new B);
    }
    else if (i == 2)
    {
        std::cout << "C was generated" << std::endl;
        return (new C);
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) 
        std::cout << "A it is" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B it is" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C it is" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A it is" << std::endl;
        return;
    } catch (std::exception &e) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B it is" << std::endl;
        return;
    } catch (std::exception &e) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C it is" << std::endl;
        return;
    } catch (std::exception &e) {}
}

int main()
{
    Base *ptr = generate();
    std::cout << "with pointer: " << std::flush;
    identify(ptr);
    std::cout << "with reference: " << std::flush;
    identify(*ptr);
    delete ptr;
    return 0;
}