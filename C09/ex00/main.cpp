#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file.\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if(!file)
    {    std::cerr << "Error: could not open file.\n";
        return 1;
    }

    
    BitcoinExchange btc;
    btc.loadingData("data.csv");
    btc.processingInput(argv[1]);

    return 0;
}

// Year-Month-Day
// bad input like 2005-99-99
/*A valid value must be either a float or a positive integer, between 0 and 1000*/
// always use the lower date