#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe aaa;
    aaa.parsing(ac,av);
    aaa.Ford_Johnson();

    return 0;
}