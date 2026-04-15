#icnldue "BitcoinExchange.hpp"


void BitcoinExchange::loadDatabase(const std::string& filename){

    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database.");

    std::string line;
    std::getline(file, line); // deppasee header "date,exchange_rate"

    while (std::getline(file, line))
    {
        // chaque ligne : "2011-01-03,0.3"
        size_t delimiterPos = line.find(',');
        if (delimiterPos != std::string::npos) {
            std::string date = line.substr(0, delimiterPos);
            std::string valueStr = line.substr(delimiterPos + 1);
            this->_db[date] = static_cast<float>(std::atof(valueStr.c_str()));
        }
    }
}

