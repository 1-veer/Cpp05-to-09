#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe aaa;
    aaa.parsing(ac,av);
    aaa.Run_Ford_Johnson();
     std::cout << "After: ";
    

    return 0;
}