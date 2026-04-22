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

eError BitcoinExchange::isValidValue(const std::string& value, float& result) const {
    // check decimal point 
    // int dicimal = 0;
    // int negatif = 0;
    // for (size_t i = 0; i < value.size(); i++){
    //     if (value[i] == '.')
    //         dicimal++;
    //     if(value[i] == '-')
    //         negatif++;
    // }
    // if(dicimal > 1)
    //     return false;
    // if(negatif != 0)
    //     return false;
    
    // // faire un check pour string value pour verfier qui touts les caracters sont des numbres !!
    // for(size_t i = 0; i < value.size(); i++){
    //     if(!isdigit(value[i]) || value[i] != '.')
    //         return false;
    // }

    std::stringstream convert(value);
    float number;
    if(!(convert >> number))
        return INVALID;
    if (number < 0)
        return NEGATIVE;
    if(number > 1000)
        return TOO_LARGE;
    // if (!(convert >> number) || number < 0 || number > 1000)
    //     return false;
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
            // if(!isValidValue(value, resul)){
            //     std::cerr << "Error: bad input => " << date << std::endl;
            //     continue ;
            // }
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
            float final_result = (std::atoi(value.c_str()) * rate);
            std::cout << date << " " << "=>" << " " << value << " " << "=>" << final_result << std::endl;
        }
        else
            std::cout << "Error: bad input => " << line << std::endl;
    }
}