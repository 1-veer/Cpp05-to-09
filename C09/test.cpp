#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>

int main ()
{
    std::vector<int> jacobsthal;

    jacobsthal.push_back(3);
    jacobsthal.push_back(5);

    int  x=5;
    for(int i = 0; x <3; i++)
    {
        x = jacobsthal[i]*2 + jacobsthal[i+1];
        jacobsthal.push_back(x);
    }


    std::cout << "jaconsthal sequence: ";
    for (std::vector<int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it)
    {   
        std::cout << *it << " ";
        
    }
    std::cout << std::endl;
    return 0;
}