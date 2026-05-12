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
    btc.setbtc(btc.loadingData("data.csv"));
    btc.processingInput(argv[1], btc.getbtc());

    return 0;
}

// didnt care about screwd up dates like : "2012-11-", "2009-11" or even "2012-2-2" or wtv , i could using a lenght check tho