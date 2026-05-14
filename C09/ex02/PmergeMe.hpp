#pragma once 
#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> vec_before;
        std::vector<int> vector;

        std::deque<int> deque_before;
        std::deque<int> deque;


    public:
    PmergeMe();
    ~PmergeMe();

    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);


    void parsing (int ac, char **av);
    void Ford_Johnson();
    void Run_Ford_Johnson();
};