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
    if(s.length() != 1)
        return false;
    if(std::isprint(static_cast <int> (s[0])) && !std::isdigit(static_cast <int> (s[0])))
        return true;
    return false;
}

e_type detect_type(std::string str) {

    if(str.empty())
        return INVALID;
    if(isInt(str))
        return INT;
    if(isChar(str))
        return CHAR;

    // check if type is doubel !
    // check if type is float !
    return INVALID;
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
    else
        std::cout << "ikhan" << std::endl;
}