#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const const BitcoinExchange& other):_db(other._db){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    if(this != &other)
        this->_db = other._db;
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}



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

    // faire un check pour valid forme
    if (date.size() != 11) return false;
    if(!isspace(date[date.size() - 1])) return false;
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
    int jour = std::atoi(date.substr(8, 2).c_str());

    // std::cout << "Le jour : " << jour << std::endl;

    if(mois < 1 || mois > 12)   return false;
    if(jour < 1 || jour > 31) return false;
    if(annee < 2009) return false;

    return true;
}

eError BitcoinExchange::isValidValue(const std::string& value, float& result) const {

    // faire un check pour valide format " value"
    if(!isspace(value[0]))
        return INVALID;
    if(isspace(value[1]))
        return INVALID;
    std::stringstream convert(value);
    float number;
    if (!(convert >> number) || !(convert >> std::ws).eof())
        return INVALID;
    if (number < 0)
        return NEGATIVE;
    if(number > 1000)
        return TOO_LARGE;
    result = number;
    return VALID;
}

float   BitcoinExchange::getRate(const std::string& date) const{

    std::map<std::string, float>::const_iterator it = this->_db.lower_bound(date);

    // trouvé exactement ✓
    if(it->first == date)
        return it->second;
    // erreur (avant toute la DB)
    if(it == _db.begin() && it->first != date)
        return -1.0f;
    // après toute la DB
    if(it == _db.end()){
        --it;
        return it->second;
    }
    // date inférieure !!
    --it;
    return it->second;
}

// pour parocessinput  commencer par cette example "2011-01-03 | 15.3"

void trim(std::string &s)
{
    size_t start = 0;
    while (start < s.length() && std::isspace(s[start]))
        start++;

    size_t end = s.length();
    while (end > start && std::isspace(s[end - 1]))
        end--;

    s = s.substr(start, end - start);
}

void    BitcoinExchange::processInput(const std::string& filename){
    std::ifstream file(filename.c_str());
    if(!file.is_open())
        throw std::runtime_error("Erorr : Impossible d'ouvrir le fichier");

    std::string line;
    // depaser le premier line "date | value" ...
    std::getline(file, line);

    while(std::getline(file, line)){
        size_t delimiterPos = line.find('|');
        if(delimiterPos != std::string::npos){
            std::string date = line.substr(0, delimiterPos);
            std::string value = line.substr(delimiterPos + 1);
            
            float resul = 0;
            if(!isValidDate(date)){
                std::cerr << "Error: bad input => " << date << std::endl;
                continue ;
            }
            eError check = isValidValue(value, resul);
            if(check == INVALID){
                std::cerr << "Error: bad input => " << value << std::endl;
                continue ;  
            }
            if(check == NEGATIVE){
                std::cerr << "Error: not a positive number." << std::endl;
                continue ;
            }
            if(check == TOO_LARGE){
                std::cerr << "Error: too large a number." << std::endl;
                continue ;
            }
            float rate = getRate(date);

            // faire un check si le data est plus ancien !!
            if(rate == -1.0f)
                std::cerr << "Error: bad input => " << date << std::endl;
            // trim(value);
            // trim(date);
            std::stringstream convert(value);
            float number;
            convert >> number;
            float final_result = (number * rate);
            std::cout << date << "" << "=>" << " " << value << " = " << final_result << std::endl;
        }
        else
            std::cout << "Error: bad input => " << line << std::endl;
    }
}