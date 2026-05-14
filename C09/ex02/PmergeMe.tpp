#include "PmergeMe.hpp"

template <typename Container>
void binary_insertion(Container &main_chain, int bigger, int smaller)
{
    typename Container::iterator pos = std::find(main_chain.begin(), main_chain.end(), bigger); // returns iterator to position
    
    typename Container::iterator it = std::lower_bound(main_chain.begin(), pos, smaller);
    main_chain.insert(it , smaller);             // lower_bound returns Iterator to the position of the number higher than smaller (can't be equal) so we insert it there and others be pushed step to the right

}

template <typename Container>
Container jacobsthal(int size)
{
    Container jacobsthal;

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