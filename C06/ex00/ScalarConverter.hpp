#pragma once

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <string>


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

