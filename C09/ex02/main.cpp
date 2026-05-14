#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

int main(int ac, char **av)
{
    PmergeMe aaa;
    if (!aaa.parsing(ac,av))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    aaa.Run_Ford_Johnson();

    return 0;
}