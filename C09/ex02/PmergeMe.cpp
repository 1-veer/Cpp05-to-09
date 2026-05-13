#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

int check_errors(std::string str)
{
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        char c = *it;

        if (!isdigit(c)) // solves tests like : 123a or -int
            return -1;
    }
    long a;
    std::stringstream ss(str) ;
    ss >> a;                 // if 'a' was int and input was > int_max it'll overflow

    if (a < 0 || a > INT_MAX)
        return -1;

    return a;
}

void PmergeMe::Execute_PmergeMe(int ac, char **av)
{
    int odd_one;
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        std::string str;
        int x;

        while (iss >> str)
        {
            x = check_errors(str);
            if (x == -1)
            {
                std::cerr << "Error." << std::endl;
                return;
            }
            this->vector.push_back(x);
        }
    }

    if (!this->vector.empty() && this->vector.size() % 2 == 1) // pulling out the odd one
        odd_one = this->vector.back();

    
}
