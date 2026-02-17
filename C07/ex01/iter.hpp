#pragma once 
#include <iostream>

template <typename AAA>
void iter(AAA* arr, const size_t len, void (*f)(AAA&))
{
    for(size_t i =0 ; i<len ; i++)
    {
        f(arr[i]);
    }
}
template <typename BBB>
void func(BBB& a)
{    
    std::cout << a << std::endl;
}   

//to handle const 

template <typename AAA>
void iter(const AAA* arr, const size_t len, void (*f)(const AAA&))
{
    for(size_t i =0 ; i<len ; i++)
    {
        f(arr[i]);
    }
}
template <typename BBB>
void func(const BBB& a)
{    
    std::cout << a << std::endl;
}


