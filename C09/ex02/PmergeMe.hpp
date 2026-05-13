#pragma once 
#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int> vector;
        std::deque<int> deque;

    public:
    PmergeMe();
    ~PmergeMe();

    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    void Execute_PmergeMe(int ac, char **av);
};