#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &other) { (void)other; }
RPN &RPN::operator=(const RPN &other) 
{
    (void)other;
    return *this;
}

bool is_operator (char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int do_math(int a , int b , char c)
{
    if (c == '+')
        return (b+a);
    else if (c == '-')
        return (b-a);
    else if (c == '*')
        return (b*a);
    else 
        return (b/a);
}

void RPN::Execute_RPN(std::string str)
{
    if (str.empty())
    {
        std::cerr << "Error." << std::endl;
        return ;
    }

    for (std::string::iterator it = str.begin(); it != str.end(); ++it) 
    {
        char c = *it;
        
        if (it == str.begin() && is_operator(c))
        {
            std::cerr<< "Error."<< std::endl;
            return ;
        }

        else if (isspace(c))
            continue;

        else if (std::isdigit(c))
        this->stack.push(c - '0');
    
        else if (is_operator(c))
        {
            if (this->stack.size() < 2)
            {
            std::cerr<< "Error."<< std::endl;
            return ;
            }
            else 
            {
                int a , b , res;

                a = this->stack.top();
                this->stack.pop();
                b = this->stack.top();
                this->stack.pop();

                if (c == '/' && a == 0) // division by 0
                {
                    std::cerr << "Error." << std::endl;
                    return;
                }

                res = do_math(a ,b, c);
                this->stack.push(res);
            }
        }
        else 
        {
            std::cerr<< "Error."<< std::endl;
            return ;
        }
    }

    if (this->stack.size() > 1 || this->stack.empty())
    {
            std::cerr<< "Error."<< std::endl;
            return ;
    }
    else 
        std::cout << this->stack.top() << std::endl;
}
