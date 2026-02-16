#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

 ScalarConverter::ScalarConverter(const ScalarConverter & ) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &) 
{
	return *this;
}

ScalarConverter::~ScalarConverter() {}

int pseudo_literals(const std::string& literal) 
{
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: nanf\n"
                  << "double: nan\n";
        return 1;
    } 
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: +inff\n"
                  << "double: +inf\n";
        return 1;
    } 
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: -inff\n"
                  << "double: -inf\n";
        return 1;
    } 
    return 0;
}


int one_char (const std::string& literal)
{
    if (!std::isdigit(literal[0]) && literal[0] != '-' && literal[0] != '+') 
    {
        if (literal.length() != 1) 
        {
            std::cout << "char: impossible\n"                      
                      << "int: impossible\n"
                      << "float: impossible\n"
                      << "double: impossible\n";
            return 1;     
        }
        std::cout << "char: '"<< literal[0] << "'\n"
                  << "int: "<< static_cast<int>(literal[0]) <<"\n"
                  << "float: "<< static_cast<float>(literal[0]) <<".0f\n"
                  << "double: "<< static_cast<float>(literal[0]) <<".0\n";
        return 1;
    }
    return 0;
}

void ScalarConverter::convert(const std::string& literal) 
{
    if (pseudo_literals(literal))
        return;
    
    if (one_char(literal))
        return;

    double value = std::stod(literal);
    if (value)
			std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";

    std::cout  << "int: "<< static_cast<int>(value) <<"\n"
               << "float: "<< static_cast<float>(value) <<".0f\n"
               << "double: "<< value <<".0\n";
}