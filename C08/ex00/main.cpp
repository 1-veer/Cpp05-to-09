#include "easyfind.hpp"
#include <vector>
#include <list>

int main ()
{
    int arr_vec[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr_vec, arr_vec + 5);

    int arr_lst[] = {10, 20, 30, 40, 50};
    std::list<int> lst(arr_lst, arr_lst + 5);

    try {
        std::vector<int>::iterator it_vec = easyfind(vec, 4);
        std::cout << "Found in vector: " << *it_vec << std::endl;

        std::list<int>::iterator it_lst = easyfind(lst, 40);
        std::cout << "Found in list: " << *it_lst << std::endl;

        
        easyfind(vec, 6); // test exception 
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception thrown : Not found" << std::endl;
    }

    return 0;
}
