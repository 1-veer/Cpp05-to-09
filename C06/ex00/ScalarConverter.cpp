#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

 ScalarConverter::ScalarConverter(const ScalarConverter & ) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &) 
{
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool pseudo_literals(const std::string& literal) 
{
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: nanf\n"
                  << "double: nan\n";
        return true;
    } 
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: +inff\n"
                  << "double: +inf\n";
        return true;
    } 
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: -inff\n"
                  << "double: -inf\n";
        return true;
    } 
    return false;
}


static bool has_invalid_leading_zero(const std::string& literal)
{
    std::size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        ++i;
    if (i >= literal.size())
        return false;
    if (literal[i] == '0' && i + 1 < literal.size() && std::isdigit((literal[i + 1])))
        return true;
    return false;
}

static bool one_char (const std::string& literal)
{
    if (literal.length() == 1 && !std::isdigit((literal[0]))) {
        std::cout << "char: '"<< literal[0] << "'\n"
                  << "int: "<< static_cast<int>(literal[0]) <<"\n"
                  << "float: "<< std::fixed << std::setprecision(1) << static_cast<float>(literal[0]) <<"f\n"
                  << "double: "<< std::fixed << std::setprecision(1) << static_cast<double>(literal[0]) <<"\n";
        return true;
    }
    if (!std::isdigit((literal[0])) && literal[0] != '-' && literal[0] != '+') {
        std::cout << "char: impossible\n"                      
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return true;
    }
    return false;
}

void ScalarConverter::convert(const std::string& literal) 
{
    if (pseudo_literals(literal))
        return;
    
    if (one_char(literal))
        return;

    if (has_invalid_leading_zero(literal)) {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }

    char* endptr = NULL;
    double value = strtod(literal.c_str(), &endptr);
    if (endptr == literal.c_str()) {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }
    if (*endptr == 'f' && *(endptr + 1) == '\0')
        ; // do nothiing
    else if (*endptr != '\0') {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
        return;
    }
    if (value < 0 || value > 127) {
        std::cout << "char: impossible\n";
    }
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(value) << "'\n";

    if (value < static_cast<double>(std::numeric_limits<int>::min())
        || value > static_cast<double>(std::numeric_limits<int>::max())) {
        std::cout << "int: impossible\n";
    } else {
        std::cout << "int: "<< static_cast<int>(value) <<"\n";
    }

    std::cout  << "float: "<< std::fixed << std::setprecision(1) << static_cast<float>(value) <<"f\n"
               << "double: "<< std::fixed << std::setprecision(1) << value <<"\n";
}