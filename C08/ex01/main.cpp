#include "Span.hpp"

// int main(void)
// {
//     try
//     {
//         Span sp = Span(5);
//         sp.addNumber(6);
//         sp.addNumber(3);
//         sp.addNumber(17);
//         sp.addNumber(9);
//         sp.addNumber(11);
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//         return (1);
//     }
//     return (0);
// }

int main(void)
{
    try
    {
        Span sp = Span(10000);
        std::vector<int> v(10000);
        for (int i = 0; i < 10000; ++i)
            v[i] = i;
        sp.addRangeOfIterators(v.begin(), v.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}


