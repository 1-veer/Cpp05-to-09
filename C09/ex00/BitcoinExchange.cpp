#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void)other; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    (void)other;
    return *this;
}

std::map<std::string, double> BitcoinExchange::getbtc()
{
    return this->data;
}

void BitcoinExchange::setbtc(std::map<std::string, double> d)
{
    this->data = d;
}

std::map<std::string, double> BitcoinExchange::loadingData(std::string str)
{
    std::map<std::string, double> data ;
    std::ifstream infile(str.c_str());
    if (!infile)
    {
        std::cerr <<  "Error: could not open infile.\n";
        return data;        
    }

    std::string s;
    std::getline(infile, s); // pass the 1st line

    while(std::getline(infile, s))
    {
        int n = s.find(',');

        std::string date = s.substr(0, n);
        std::string str_val = s.substr(n+1);

        std::stringstream ss(str_val);
        double val;

        if (!(ss >> val))
        continue;

        data[date] = val;
    }
    
    return data;
}

bool check_range(double &val)
{
    if (val > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    if (val < 0.0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
   
    return true;
}

bool check_bad_input (std::string & date, size_t &n)
{
    int n1 = date.find('-');
    int n2 = date.find('-', n1+1);
    std::string s_year = date.substr(0, n1-1);
    std::string s_month = date.substr(n1+1, n2-1);
    std::string s_day = date.substr(n2+1);

    std::stringstream ssy(s_year);
    std::stringstream ssm(s_month);
    std::stringstream ssd(s_day);
    int year, month, day;
    
    if (!(ssy >> year) || !(ssm >> month) || !(ssd >> day))
        return false;
    

    if (month > 12 || month <= 0 || day > 31 || day <= 0)
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return false;
    }

    if(n== std::string::npos) 
    {
        std::cerr << "Error: bad input. " << std::endl;
        return false;
    }

    return true;
}

void BitcoinExchange::processingInput(std::string str, const std::map<std::string, double> &data)
{
    std::ifstream infile(str.c_str());
    if (!infile)
    {
        std::cerr <<  "Error: could not open input file.\n";
        return ;        
    }

    std::string s;
    std::getline(infile, s);
    if (s != "date | value")
    {
        std::cerr <<  "Error: use the accurate header: \"date | value\"" << std::endl;
        return;
    }  

    while(std::getline(infile, s))
    {
        size_t n = s.find('|');

        if (n-1 < 0 || n+2 >= s.size())
        {
            std::cerr <<  "Error: bad input.\n";
            continue;
        }
        std::string date = s.substr(0, n-1);
        std::string str_val = s.substr(n+2);

        std::stringstream ss(str_val);
        double val;

        if (!(ss >> val))
        {
            std::cerr << "Error: bad input." << std::endl;
            continue;
        }

        
        if (!check_range(val))
            continue;
        
        if (!check_bad_input(date,n))
            continue;
        
        std::map<std::string, double>::const_iterator it = data.lower_bound(date);
         
        if (it == data.end())
        {
                std::cerr << "Error: out of database's range." << std::endl;
                continue;
            }
        if (it ->first == date)
        {
            std::cout << date << " => " << val << " = " << std::flush;
            std::cout << val * it-> second << std::endl;
        }
        else 
        {
            if (it == data.begin())
            {
                std::cerr << "Error: out of database's range." << std::endl;
                continue;
            }

            it--; // we need lower date not the higher one
            std::cout << date << " => " << val << " = " << std::flush;
            std::cout << val * it-> second << std::endl;
        }
    } 
}

// If all the keys in the map are less than k, returns iterator to the end of the map. , we cant access it 
// If all the keys in the map are greater than k, returns iterator to the beginning of the range , it will skip the first if