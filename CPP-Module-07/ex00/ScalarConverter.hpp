#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>

#define int_min std::numeric_limits<int>::min()
#define int_max std::numeric_limits<int>::max()
#define float_min std::numeric_limits<float>::min()
#define float_max std::numeric_limits<float>::max()
#define double_min std::numeric_limits<double>::min()
#define double_max std::numeric_limits<double>::max()
enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL, // For nan, inf, etc. rak 3arf likayn
    INVALID  // chy haja khrb9a makaatntamich l  data li 3ndna 
};

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        ~ScalarConverter();
        static void convert(const std::string &literal);
        static void convertFromChar(char c);
        static void convertFromInt(int i);
        static void convertFromFloat(float f);
        static void convertFromDouble(double d);
        static void convertFromSpecial(const std::string &s);
};


#endif