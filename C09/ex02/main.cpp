#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

int main(int ac, char **av)
{
    PmergeMe aaa;
    if (ac < 2 || !aaa.parsing(ac,av))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try 
    {
        aaa.Run_Ford_Johnson();
    }

    catch (...) 
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    return 0;
}