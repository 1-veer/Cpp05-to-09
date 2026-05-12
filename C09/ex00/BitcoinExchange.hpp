#pragma once 
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


class BitcoinExchange
{
    private:
        std::map<std::string, double> data;    

    public:
    BitcoinExchange();
    ~BitcoinExchange();

    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);

    std::map<std::string, double>  getbtc(void);
    void setbtc (std::map<std::string, double> d);

    std::map<std::string, double> loadingData(std::string);
    void processingInput(std::string, const std::map<std::string, double> &);





};