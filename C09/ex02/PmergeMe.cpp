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


void binary_insertion (std::vector<int> &main_chain, int bigger, int smaller)
{
    std::vector<int>::iterator pos = std::find(main_chain.begin(), main_chain.end(), bigger); // returns iterator to position
    
    std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), pos, smaller);
    main_chain.insert(it , smaller);             // lower_bound returns Iterator to the position of the number higher than smaller (can't be equal) so we insert it there and others be pushed step to the right
}

// inary search is most efficient when the size of the array it searches is exactly one less than a power of 2.

void PmergeMe::parsing(int ac, char **av)
{
    for (int i = 1; i < ac; i++)
    {
        std::istringstream iss(av[i]);
        std::string str;
        int x;

        while (iss >> str)
        {
            x = check_errors(str);
            if (x == -1 || std::find(this->vector.begin(), this->vector.end(), x) != this->vector.end()) // error or duplicate
            {
                std::cerr << "Error." << std::endl;
                return;
            }

            this->vector.push_back(x);
        }
    }
}

int is_sorted(std::vector<int> vec)
{
    for (std::vector<int>::iterator it = vec.begin() + 1; it != vec.end(); ++it)
    {
        if (*it < *(it-1))
        return 0;
    }
    return 1;
}

std::vector<int> jacobsthal(int size)
{
    std::vector<int> jacobsthal;

    jacobsthal.push_back(3);
    jacobsthal.push_back(5);
    int  x=5; // so the loop below only activates if we have a size bigger than 5 else we just need [3 , 5]

    for(int i = 0; x < size; i++)
    {
        x = jacobsthal[i]*2 + jacobsthal[i+1];
        jacobsthal.push_back(x);
    }
    return jacobsthal;
}

void PmergeMe::Ford_Johnson()
{
    if (this->vector.size() <= 1)
        return;

    int odd_one = -1;
    std::vector< std::pair<int, int> > pairs;
    if (!this->vector.empty() && this->vector.size() % 2 == 1) // pulling out the odd one
        odd_one = this->vector.back();

    std::vector<int> vec_before = this->vector;


    std::cout << std::endl;

    for (std::vector<int>::iterator it = this->vector.begin(); it + 1 < this->vector.end(); it += 2)
    {
        pairs.push_back(std::make_pair(*it, *(it+1)));
    }
    
    std::vector<int> main_chain;
    
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) // sort pairs , larger first
    {
        if (it->first < it->second) 
            std::swap(it->first, it->second);
        main_chain.push_back(it->first);
    }

    this->vector = main_chain;
    this->Ford_Johnson();
    main_chain = this->vector;
    this->vector = vec_before;
    
    std::vector<int> pending;
    for (std::vector<int>::iterator mainchain_it = main_chain.begin(); mainchain_it != main_chain.end(); ++mainchain_it) // we loop thro all the sorted main chain elements to find their match in the pairs to insert that pairs second in the pending list
    {
        for (std::vector<std::pair<int, int> >::iterator pairs_it = pairs.begin(); pairs_it != pairs.end(); ++pairs_it)
        {
            if (*mainchain_it == pairs_it->first)   // if this element of the main chain the same as the one of the pairs's first "finding a match"
            {
                pending.push_back(pairs_it->second);
                break;
            }
        }
    }

    // // Debug prints to prove the alignment holds
    // std::cout << "Main chain: ";
    // for (size_t i = 0; i < main_chain.size(); i++) std::cout << main_chain[i] << " ";
    // std::cout << "\nPending:    ";
    // for (size_t i = 0; i < pending.size(); i++) std::cout << pending[i] << " ";
    // std::cout << "\n" << std::endl;
    
    // we add our a1 free pass
    if (!pending.empty())
    {
        main_chain.insert(main_chain.begin(), pending[0]);
        // pending.erase(pending.begin());
    }

    int last_indx = 1; // we already insterted index 0 
    std::vector<int> jacob_seq = jacobsthal(pending.size());

    for (size_t i = 1; i < jacob_seq.size(); i++)    
    {
        int currnt_jacob = jacob_seq[i];
        if (currnt_jacob > pending.size())   // for example if we have 9 but the jacob is 11
            currnt_jacob = pending.size();   
    
        for (int j = currnt_jacob -1; j >= last_indx; j-- ) // current - 1 is like from b1 to being index 0 and 3 in jacob is inex 2
        {
            int smaller = pending[j];
            int bigger = whatever
        }
    }
    



    // loop pairs to find bigger when we have smaller


    this->vector = main_chain;
}






/*
std::cout << "main chain: ";
    for (std::vector<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
    {   
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "pending: ";
    for (std::vector<int>::iterator it = pending.begin(); it != pending.end(); ++it)
    {   
        std::cout << *it << " ";
        
    }
    std::cout << std::endl;
    std::cout << odd_one <<std::endl;
*/