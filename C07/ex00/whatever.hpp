#pragma once 
#include <iostream>

template <typename AAA>
void swap (AAA& a ,AAA& b) 
{
    AAA tmp = a ;
    a = b;
    b = tmp;
}

template <typename AAA>
AAA min(AAA a, AAA b)
{
    return (a >= b ? b : a);
}

template <typename AAA>
AAA max(AAA a, AAA b)
{
    return (a <= b ? b : a);
}
