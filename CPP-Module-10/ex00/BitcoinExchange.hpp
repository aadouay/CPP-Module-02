#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <cstdlib>
# include <sstream>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        void    loadDatabase(const std::string& filename);
        void    processInput(const std::string& filename);

    private:
        std::map<std::string, float> _db;

        bool    isValidDate(const std::string& date) const;
        bool    isValidValue(const std::string& value, float& result) const;
        float   getRate(const std::string& date) const;
};

#endif