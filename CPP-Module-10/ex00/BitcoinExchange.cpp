#include "BitcoinExchange.hpp"


void BitcoinExchange::loadDatabase(const std::string& filename){

    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error : Impossible d'ouvrir le database.");

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

bool BitcoinExchange::isValidDate(const std::string& date) const {

    // faire un check pour le caracter "-" si trouve deux exactement !!

    if(date[4] != '-' || date[7] != '-')
        return false;
    // faire un check sur loop pour verfiee est ce que tout les alphabets est numerics !!

    for (size_t i = 0; i < 10; i++)
    {
        if(i == 4 || i == 7) continue ;
        if(!std::isdigit(date[i]))
            return false;
    }
    
    // faire un check si la date est validee !
    // example : "2011-01-03"
    int annee = std::atoi(date.substr(0, 4).c_str());
    int mois = std::atoi(date.substr(5, 2).c_str());
    int jour = std::atoi(date.substr(7, 2).c_str());

    if(mois < 1 || mois > 12)   return false;
    if(jour < 1 || jour > 31) return false;
    if(annee < 2009) return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value, float& result) const {

}
