#pragma once 
#include <iostream>
#include <algorithm>


template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), to_find);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}