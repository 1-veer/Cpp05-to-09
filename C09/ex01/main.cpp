#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Wrong usage! , try : ./RPN arg" << std::endl;
        return 1;
    }

    RPN aaa;
    aaa.Execute_RPN(argv[1]);

    return 0;
}