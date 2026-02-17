#include "iter.hpp"

int main()
{
    std::cout<<"---Test with integers---"<<std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    iter<int>(arr, 5, func);

    std::cout<<"---Test with strings---"<<std::endl;
    std::string str[] = {"Hello", "World", "!"};
    iter<std::string>(str, 3, func);

    std::cout<<"---Test with chars---"<<std::endl;
    char chars[] = {'A', 'B', 'C', 'D'};
    iter<char>(chars, 4, func);

    std::cout<<"---Test with floats---"<<std::endl;
    float floats[] = {1.1f, 2.2f, 3.3f};
    iter<float>(floats, 3, func);

    std::cout<<"---Test with doubles---"<<std::endl;
    double doubles[] = {1.11, 2.22, 3.33};
    iter<double>(doubles, 3, func);
}
