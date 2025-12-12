#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <cmath> // for std::isinf and std::isnan

// void parse_float_string(const std::string& input) {
//     std::stringstream ss(input);
//     float value;
//     ss >> value;

//     std::cout << "Input: " << input << ", Value: " << value << std::endl;

//     if (std::isinf(value)) {
//         std::cout << "  -> This is infinity." << std::endl;
//     } else if (std::isnan(value)) {
//         std::cout << "  -> This is not a number (NaN)." << std::endl;
//     }
// }

int main() {
    // std::cout << "--- Float Suffix Values (float) ---" << std::endl;
    // parse_float_string("-inff");
    // parse_float_string("+inff");
    // parse_float_string("nanf");

    // // The functions also work for double formats when parsing into a float variable
    // std::cout << "\n--- Double Format Values (float interpretation) ---" << std::endl;
    // parse_float_string("-inf");
    // parse_float_string("+inf");
    // parse_float_string("nan");

    std:: cout << (-1.0f / 0.0f) ;

    return 0;
}