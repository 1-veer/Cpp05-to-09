#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "===== DEFAULT CONSTRUCTOR =====" << std::endl;
    Array<int> empty;
    std::cout << "Size of empty array: " << empty.size() << std::endl;

    std::cout << "\n===== PARAMETER CONSTRUCTOR =====" << std::endl;
    Array<int> a(5);
    std::cout << "Size of a: " << a.size() << std::endl;

    std::cout << "Initialize elements:" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;

    std::cout << "\n===== COPY CONSTRUCTOR =====" << std::endl;
    Array<int> b(a);

    std::cout << "Modify original array a..." << std::endl;
    a[0] = 999;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] (should be unchanged) = " << b[0] << std::endl;

    std::cout << "\n===== ASSIGNMENT OPERATOR =====" << std::endl;
    Array<int> c;
    c = a;

    std::cout << "Modify original array again..." << std::endl;
    a[1] = 555;

    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "c[1] (should be unchanged) = " << c[1] << std::endl;

    std::cout << "\n===== OUT OF BOUNDS TEST =====" << std::endl;
    try
    {
        std::cout << a[100] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: index out of bounds" << std::endl;
    }

    std::cout << "\n===== CONST ARRAY TEST =====" << std::endl;
    const Array<int> d(3);
    std::cout << "Size of const array: " << d.size() << std::endl;

    try
    {
        std::cout << d[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught in const access" << std::endl;
    }

    std::cout << "\n===== TEMPLATE WITH OTHER TYPES =====" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "Template";

    for (unsigned int i = 0; i < strArray.size(); i++)
        std::cout << strArray[i] << std::endl;

    return 0;
}
