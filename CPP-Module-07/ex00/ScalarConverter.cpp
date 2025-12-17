#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){  
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter(){}

// Implementation of member functions

void    ScalarConverter::convertFromChar(char c){

    printf("Converting from char \n");

    if(std::isprint(c))
        std::cout << "char : '" << c << "'" << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
    std::cout << "int : " << static_cast<int>(c) << std::endl;
    if(c - static_cast<int>(c) == 0.0f)
        std::cout << "float : " << static_cast<float>(c) << ".0f" << std::endl;
    else
        std::cout << "float : " << static_cast<float>(c) << "f" << std::endl;
    if(c - static_cast<int>(c) == 0.0)
        std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
    else
        std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void    ScalarConverter::convertFromInt(double i){

    if(i >= 0 && i <= 127 && std::isprint(static_cast<char>(i)))
        std::cout << "char : '" << static_cast<char>(i) << "'" << std::endl;
    else if((i >= 0 && i <= 127) && !std::isprint(static_cast<char>(i)))
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : impossible" << std::endl;
    if(i >= static_cast<double>(int_min) && i <= static_cast<double>(int_max))
        std::cout << "int : " << static_cast<int>(i) << std::endl;
    else
        std::cout << "int : impossible" << std::endl;
    if(i - static_cast<int>(i) == 0.0f)
        std::cout << "float : " << static_cast<float>(i) << ".0f" << std::endl;
    else
        std::cout << "float : " << static_cast<float>(i) << "f" << std::endl;
    // don't  forget handle ouverflow for double & float here
    if(i - static_cast<int>(i) == 0.0)
        std::cout << "double : " << static_cast<double>(i) << ".0" << std::endl;
    else
        std::cout << "double : " << static_cast<double>(i) << std::endl;
}


void    ScalarConverter::convertFromFloat(float f){

    if(f >= 0 && f <= 127 && std::isprint(static_cast<char>(f)))
        std::cout << "char : '" << static_cast<char>(f) << "'" << std::endl;
    else if((f >= 0 && f <= 127) && !std::isprint(static_cast<char>(f)))
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : impossible" << std::endl;
    if(f >= static_cast<float>(int_min) && f <= static_cast<float>(int_max))
        std::cout << "int : " << static_cast<int>(f) << std::endl;
    else
        std::cout << "int : impossible" << std::endl;
    // don't  forget handle ouverflow for double & float here
    if(f - static_cast<int>(f) == 0.0f)
        std::cout << "float : " << f << ".0f" << std::endl;
    else
        std::cout << "float : " << f << "f" << std::endl;
    // don't  forget handle ouverflow for double & float here
    if(f - static_cast<int>(f) == 0.0)
        std::cout << "double : " << static_cast<double>(f) << ".0" << std::endl;
    else
        std::cout << "double : " << static_cast<double>(f) << std::endl;
}

void    ScalarConverter::convertFromDouble(double d){

    if(d >= 0 && d <= 127 && std::isprint(static_cast<char>(d)))
        std::cout << "char : '" << static_cast<char>(d) << "'" << std::endl;
    else if((d >= 0 && d <= 127) && !std::isprint(static_cast<char>(d)))
        std::cout << "char : Non displayable" << std::endl;
    else
        std::cout << "char : impossible" << std::endl;
    if(d >= static_cast<double>(int_min) && d <= static_cast<double>(int_max))
        std::cout << "int : " << static_cast<int>(d) << std::endl;
    else
        std::cout << "int : impossible" << std::endl;
    // don't  forget handle ouverflow for double & float here

    if(d - static_cast<int>(d) == 0.0f)
        std::cout << "float : " << static_cast<float>(d) << ".0f" << std::endl;
    else
        std::cout << "float : " << static_cast<float>(d) << "f" << std::endl;
    // don't  forget handle ouverflow for double & float here
    if(d - static_cast<int>(d) == 0.0)
        std::cout << "double : " << d << ".0" << std::endl;
    else
        std::cout << "double : " << d << std::endl;
}

void    ScalarConverter::convertFromSpecial(const std::string &s){
    std::cout << "char : impossible" << std::endl;
    std::cout << "int : impossible" << std::endl;
    if(s == "nan" || s == "nanf"){
        std::cout << "float : nanf" << std::endl;
        std::cout << "double : nan" << std::endl;
    }
    else if(s == "+inf" || s == "+inff"){
        std::cout << "float : +inff" << std::endl;
        std::cout << "double : +inf" << std::endl;
    }
    else if(s == "-inf" || s == "-inff"){
        std::cout << "float : -inff" << std::endl;
        std::cout << "double : -inf" << std::endl;
    }
}

// Helper functions to detect type
bool isInt(const std::string &s) {
    size_t i = 0;
    if (s[i] == '-' || s[i] == '+') i++;
    if (i == s.length()) return false; // had zmar makhdamch 
    for (; i < s.length(); i++)
        if (!std::isdigit(s[i])) return false;
    return true;
}

bool isChar(const std::string &s)
{
    if(s.length() != 3)
        return false;
    if(!(s[0] == '\'' && s[2] == '\''))
        return false;
        
    return true;
}

bool isDoubel(const std::string &s){

    int count = 0;
    double number = 0;
    // check if we have valid format . &&  numbers !!

    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if(!(s[i] == '.'  || s[i] == '-' || s[i] == '+' || (s[i] >= '0' && s[i] <= '9')))
            return false;
    }

    for (size_t i = 1; i < s.length(); i++){
        if(s[i] == '-' || s[i] == '+')
            return false;
    }
    // check how many dots exits !!
    int i = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '.')
            count++;
    }
    if(count != 1)
        return false;
    if(s[0] == '.' || s[s.length() - 1] == '.')
        return false;
    return true;
}

bool isFloat(const std::string &s){
    int count = 0;
    double number = 0;
    // check if we have valid format . & f & numbers !!

    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if(!(s[i] == '.' || s[i] == 'f' || s[i] == '-' || s[i] == '+'|| (s[i] >= '0' && s[i] <= '9')))
            return false;
    }
    
    for (size_t i = 1; i < s.length(); i++){
        if(s[i] == '-' || s[i] == '+')
            return false;
    }
    // check how many dots exits !!
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '.')
            count++;
    }
    if(count != 1)
        return false;
    if(s[s.length() - 1] == '.')
        return false;
    //check valid pos of f character !
    for (size_t i = 0; i < (s.length() - 1); i++){
        if(s[i] == 'f')
            return false;
    }
    // special case .f
    for(size_t i = 0; i < s.length(); i++){
        if(s[i] == '.' && s[i + 1] == 'f' && s[i +  2] == '\0')
            return true;
    }
    return true;
}

bool isSpecial(const std::string &s) {
    if (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff" || s == "-inf" || s == "-inff")
        return true;
    return false;
}

e_type detect_type(std::string str) {

    if(isInt(str))
        return INT;
    if(isChar(str))
        return CHAR;
    if(isDoubel(str))
        return DOUBLE;
   if(isFloat(str))
        return FLOAT;
    if(isSpecial(str))
        return SPECIAL;
    return INVALID;
}

void    convert_the_string(std::string str, e_type type){

    switch(type){
        case CHAR:
            ScalarConverter::convertFromChar(str.c_str()[1]);
            break;
        case INT:
            ScalarConverter::convertFromInt(std::strtod(str.c_str(), NULL));
            break;
        case FLOAT:
            ScalarConverter::convertFromFloat(std::strtod(str.c_str(), NULL));
            break;
        case DOUBLE:
            ScalarConverter::convertFromDouble(std::strtod(str.c_str(), NULL));
            break;
        case SPECIAL:
            ScalarConverter::convertFromSpecial(str);
            break;
        default:
            std::cout << "Invalid input" << std::endl;
    }
}

void    ScalarConverter::convert(const std::string &literal){
    e_type type = detect_type(literal);
    convert_the_string(literal, type);
}