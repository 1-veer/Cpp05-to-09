#pragma once

#include <iostream>

class ScalarConverter
{
    private:
    static convert

    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&other);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter();

};

std::ostream& operator<<(std::ostream& out, const ScalarConverter& ScalarConverter);

