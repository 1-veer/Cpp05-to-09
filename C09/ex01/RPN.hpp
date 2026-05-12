#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>


class RPN
{
    private:
        std::stack<int> stack;

    public:
    RPN();
    ~RPN();

    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    void Execute_RPN(std::string);
};

/*
    push , pop , top , size() , empty()
*/