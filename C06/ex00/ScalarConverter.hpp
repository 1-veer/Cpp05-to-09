#pragma once

#include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter &);

    public:
        ~ScalarConverter();
        static void convert(const std::string& literal);
};

