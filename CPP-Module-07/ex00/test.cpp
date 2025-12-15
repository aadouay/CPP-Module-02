#include <iostream>
#include <string>
#include <cctype>

enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL, // For nan, inf, etc. rak 3arf likayn
    INVALID  // chy haja khrb9a makaatntamich l  data li 3ndna 
};

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
    if(s[0] == '.' || s[s.length() - 1] == '.')
        return false;
    //check valid pos of f character !
    for (size_t i = 0; i < (s.length() - 1); i++){
        if(s[i] == 'f')
            return false;
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

    if(type == INVALID){
        std::cout << "char : impossible" << std::endl;
        std::cout << "int : impossible" << std::endl;
        std::cout << "float : impossible" << std::endl;
        std::cout << "doubel : impossible" << std::endl;
    }
}
// then if we have invalid we should return imposible in all types !
// if type is valid we should return ech type withe her casting using static cast !

int main(int ac, char **av){
    if (ac != 2)
    {
        std::cout << "Error !" << std::endl;
        return 1;
    }
    if(detect_type(av[1]) == INT)
        std::cout << "INT"<< std::endl;
    else if(detect_type(av[1]) == CHAR)
        std::cout << "CHAR"<< std::endl;
    else if(detect_type(av[1]) == DOUBLE)
        std::cout << "DOUBLE" << std::endl;
    else if(detect_type(av[1]) == FLOAT)
        std::cout << "FLOAT" << std::endl;
    else
        std::cout << "ikhan" << std::endl;
}