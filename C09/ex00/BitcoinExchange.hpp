#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


class BitcoinExchange
{
    private:
        std::map<std::string, double> btcchange;    

    public:
    BitcoinExchange();
    ~BitcoinExchange();

    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    void loadingData(std::string);
    
    void processingInput(std::string);










};