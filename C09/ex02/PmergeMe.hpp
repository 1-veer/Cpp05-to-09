#pragma once 
#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>

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


    void parsing (int ac, char **av);
    void Ford_Johnson();
};